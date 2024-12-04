#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph {
public:
    DenseGraph() {
        n = 3;
        vec.resize(3, vector<bool>(3,false));
    }

    DenseGraph(int n_in) {
        n = n_in;
        vec.resize(n_in, vector<bool>(n_in, false));
    }

    DenseGraph(const DenseGraph& G) {
        n = G.n;
        vec = G.vec;
    }

    void AddEdge(int a, int b) {
        vec[a][b] = true;
    }

    void RemoveEdge(int a, int b) {
        vec[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        return vec[a][b];
    }

    DenseGraph Transpose() const {
        DenseGraph temp(n);
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                temp.vec[i][j] = vec[j][i];
            }
        }
        return temp;
    }

protected:
    int n;
    vector<vector<bool>> vec;
};
#endif // __DENSE_GRAPH_H__
