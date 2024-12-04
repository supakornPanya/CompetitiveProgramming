#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    set<T> s;
    vector<T> v;
    for(size_t i = 0;i < A.size();i++) {
        if(s.find(A[i]) != s.end()) continue;
        v.push_back(A[i]);
        s.insert(A[i]);
    }
    for (size_t i = 0;i < B.size();i++) {
        if (s.find(B[i]) != s.end()) continue;
        v.push_back(B[i]);
        s.insert(B[i]);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    set<T> s;
    vector<T> v;
    for (size_t i = 0;i < B.size();i++) {
        s.insert(B[i]);
    }
    for (size_t i = 0;i < A.size();i++) {
        if (s.find(A[i]) == s.end()) continue;
        v.push_back(A[i]);
        s.insert(A[i]);
    }
    return v;
}
