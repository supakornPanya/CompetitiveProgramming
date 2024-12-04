#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int k, int now, vector<bool>& sol, bool pass, int consec) {
    if (consec >= k) pass = true;
    if (now >= n) {
        if (pass) {
            for (int i = 0;i < sol.size();i++) {
                cout << sol[i];
            } cout << '\n';
        }
        return;
    }

    sol.push_back(false);
    bfs(n, k, now + 1, sol, pass, 0);
    sol.pop_back();

    sol.push_back(true);
    bfs(n, k, now + 1, sol, pass, consec + 1);
    sol.pop_back();
}

int main() {
    int n, k; cin >> n >> k;
    vector<bool> sol;
    bfs(n, k, 0, sol, false, 0);
}