#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) { cin >> v[i]; }
    int ans = 0;

    for (int i = 0;i < n;i++) {
        int val = 0, found1 = 0, found2 = 0;
        for (int j = 0;j < n - found1;j++) {
            if (found1 >= 2 || found2 >= 2) break;
            int now = i + j + found1;
            val += v[now % n];
            // cout << "i : " << i << ", j : " << j << ", now : " << now % n << ", v[now] : " << v[now % n];
            // cout << ", val : " << val << ", found1 : " << found1 << endl;
            if (v[now % n] > v[(now + 1) % n]) {
                if (v[now % n] <= v[(now + 2) % n]) {
                    found1++; found2++;
                } else if (v[(now + 1) % n] > v[(now + 2) % n]) {
                    break;
                } else { //v[(now + 1) % n] <= v[(now + 2) % n]
                    ans = max(ans, val);
                    if (v[(now + n - 1) % 
                    
                    n] <= v[(now + 1) % n]) {
                        val -= v[now % n];
                        found2++;
                        continue;
                    }
                    break;
                }
            }
        }
        ans = max(ans, val);
    }

    cout << ans;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n; cin >> n;
//     vector<int> v(n);
//     for (int i = 0;i < n;i++) { cin >> v[i]; }
//     int ans = 0;

//     for (int i = 0;i < n;i++) {
//         int val = 0, found1 = 0, found2 = 0;
//         for (int j = 0;j < n - found1;j++) {
//             if (found1 >= 2 || found2 >= 2) break;
//             val += v[(i + j + found1) % n];
//             if (v[(i + j + found1) % n] > v[(i + j + found1 + 1) % n]) {
//                 if (v[(i + j + found1) % n] <= v[(i + j + found1 + 2) % n]) {
//                     found1++; found2++;
//                 } else if (v[(i + j + found1 + 1) % n] > v[(i + j + found1 + 2) % n]) {
//                     break;
//                 } else {
//                     ans = max(ans, val);
//                     if (v[(i + j + found1 + n - 1) % n] <= v[(i + j + found1 + 1) % n]) {
//                         val -= v[(i + j + found1) % n];
//                         found2++;
//                         continue;
//                     }
//                     break;
//                 }
//             }
//         }
//         ans = max(ans, val);
//     }

//     cout << ans;
// }