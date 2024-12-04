#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<bool>& sol, int m) {
    if (0 > m) return;
    if (0 >= n) {
        if (0 == m && 0 == n) {
            for (int i = 0;i < sol.size();i++) {
                cout << sol[i];
            }cout << '\n';
        }
        return;
    }
    sol.push_back(false);
    dfs(n - 1, sol, m);
    sol.pop_back();

    sol.push_back(true);
    dfs(n - 1, sol, m - 1);
    sol.pop_back();
}

int main() {
    int m, n; cin >> m >> n;
    vector<bool> sol;
    dfs(n, sol, m);
}

// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int n, int now, vector<int>& sol, int m, int one) {
//     if(one > m) return ;
//     if(now >= n){
//         if(one == m && now == n) {
//             for(int i = 0;i < sol.size();i++) {
//                 cout << sol[i];
//             }cout << '\n';
//         } 
//         return ;
//     }
//     sol.push_back(0);
//     dfs(n, now + 1, sol, m, one);
//     sol.pop_back();

//     sol.push_back(1);
//     dfs(n, now + 1, sol, m, one + 1);
//     sol.pop_back();
// }

// int main() {
//     int m, n; cin >> m >> n;
//     vector<int> sol;
//     dfs(n, 0, sol, m, 0);
// }