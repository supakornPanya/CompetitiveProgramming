#include <bits/stdc++.h>
using namespace std;

int f(int n, int now, vector<bool>& flag) {
    if(now >= n) return 0;
    flag[now] = true;
    int l = f(n, now*2 + 1, flag);
    int r = f(n, now*2 + 2, flag);
    return 1 + l + r;
}

int main() {
    int n, start; cin >> n >> start;
    vector<bool> flag(n); flag[start] = true;
    int sizee = f(n, start, flag);
    cout << n - sizee << '\n';
    for(int i = 0;i < n;i++) {
        if(flag[i]) continue;
        cout << i << " ";
    }
}











//round 1-----------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> comp; //complement
// void process(int n, int k) {
//     if (((2 * k) + 1) < n) {
//         comp.push_back((2 * k) + 1);
//         process(n, (2 * k) + 1);
//     }
//     if (((2 * k) + 2) < n) {
//         comp.push_back((2 * k) + 2);
//         process(n, (2 * k) + 2);
//     }
//     return;
// }

// int main() {
//     int n, k; cin >> n >> k;
//     comp.push_back(k);
//     process(n, k);
//     int idx = 0;
//     // cout << "size " << comp.size() << '\n';
//     // for(int i = 0;i < comp.size();i++) {
//     //     cout << comp[i] << " ";
//     // } cout << '\n';
//     sort(comp.begin(), comp.end());
//     cout << n - comp.size() << '\n';
//     for (int i = 0;i < n;i++) {
//         if (comp[idx] == i) {
//             idx++;
//             continue;
//         }
//         cout << i << " ";
//     }
// }