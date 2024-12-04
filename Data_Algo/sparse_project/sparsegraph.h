#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <unordered_set>
#include <utility> // For std::pair

// Define a hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
    }
};

class SparseGraph {
public:
    SparseGraph() : n(3) {}

    SparseGraph(int n_in) : n(n_in) {}

    SparseGraph(const SparseGraph& G) : n(G.n), s(G.s) {}

    void AddEdge(int a, int b) {
        s.insert({ a, b });
    }

    void RemoveEdge(int a, int b) {
        auto it = s.find({ a, b });
        if (it != s.end()) s.erase(it);
    }

    bool DoesEdgeExist(int a, int b) const {
        return s.find({ a, b }) != s.end();
    }

    SparseGraph Transpose() const {
        SparseGraph temp;
        temp.n = n;
        for (const auto& it : s) {
            temp.s.insert({ it.second, it.first });
        }
        return temp;
    }

protected:
    int n;
    std::unordered_set<std::pair<int, int>, pair_hash> s;
};

#endif // __SPARSE_GRAPH_H__
