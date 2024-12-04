#include <bits/stdc++.h>
using namespace std;

void recur(int a, int b, vector<vector<int>>& v, int i, int j) {
    if (a == 0) {
        v[i][j] = b;
        return;
    }

    recur(a - 1, b, v, i, j);
    recur(a - 1, b - 1, v, i, j + pow(2, a-1));
    recur(a - 1, b + 1, v, i + pow(2, a - 1), j);
    recur(a - 1, b, v, i + pow(2, a-1), j + pow(2, a-1));
    return;
}

int main() {
    int a, b; cin >> a >> b;
    vector<vector<int>> v(pow(2, a), vector<int>(pow(2, a)));
    recur(a, b, v, 0, 0);

    for (int i = 0;i < v.size();i++) {
        for (int j = 0;j < v[0].size();j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}