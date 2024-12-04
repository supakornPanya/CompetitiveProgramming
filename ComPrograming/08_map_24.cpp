#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1; cin >> n1;
    map<string, double> m, ans;
    for (int i = 0;i < n1;i++) {
        string s; double x; cin >> s >> x;
        m[s] = x;
    }

    int n2; double sum = 0; cin >> n2;
    for (int i = 0;i < n2;i++) {
        string s; double x; cin >> s >> x;
        if (m[s] != 0) {
            ans[s] += (m[s] * x);
            sum += (m[s] * x);
        }
    }

    vector<pair<double, string>> v;
    for (auto it = ans.begin();it != ans.end();it++) {
        v.push_back({ it->second, it->first });
    }
    sort(v.rbegin(), v.rend());

    if (sum == 0) {
        cout << "No ice cream sales";
    } else {
        cout << "Total ice cream sales: " << sum << endl;
        cout << "Top sales: ";
        double maxx = v[0].first;
        for (int i = v.size() - 1;i >= 0;i--) {
            if (v[i].first != maxx) break;
            cout << v[i].second << " ";
        }
        cout << endl;
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1; cin >> n1;
//     map<string, double> m, ans;
//     for (int i = 0;i < n1;i++) {
//         string s; double x; cin >> s >> x;
//         m[s] = x;
//     }

//     int n2; double sum = 0; cin >> n2;
//     for (int i = 0;i < n2;i++) {
//         string s; double x; cin >> s >> x;
//         if (m[s] != 0) {
//             ans[s] += (m[s] * x);
//             sum += (m[s] * x);
//         }
//     }

//     vector<pair<double, string>> v;
//     for (auto it = ans.begin();it != ans.end();it++) {
//         v.push_back({ it->second, it->first });
//     }
//     sort(v.rbegin(), v.rend());

//     if (sum == 0) {
//         cout << "No ice cream sales";
//     } else {
//         cout << "Total ice cream sales: " << sum << endl;
//         cout << "Top sales: ";
//         double maxx = v[0].first;
//         for (int i = v.size() - 1;i >= 0;i--) {
//             if (v[i].first != maxx) break;
//             cout << v[i].second << " ";
//         }
//         // for (int i = 0;i < v.size();i++) {
//         //     if (v[i].first != maxx) break;
//         //     cout << v[i].second << " ";
//         // }
//         cout << endl;
//     }

//     return 0;
// }