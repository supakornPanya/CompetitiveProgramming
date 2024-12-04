#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q; cin >> q;
    set<pair<int, int>> sp; //set pair(int,int)
    for (int i = 0;i < q;i++) {
        int opr; cin >> opr;
        if (opr == 1) {
            int s, e; cin >> s >> e;
            auto it = (sp.insert({ s,e })).first; //position insert
            //case : merge prev (end prev in start new)
            if (it != sp.begin()) {
                auto prev = it; prev--;
                if (it->first - 1 <= prev->second) {
                    int val1 = it->first;
                    int val2 = max(it->second, prev->second);
                    sp.erase(*prev);
                    sp.erase(*it);
                    it = (sp.insert({ val1, val2 })).first;
                }
            }
            //case : merge next (end new in start next)
            auto next = it; next++;
            // cout << "it2 : " << it->first << ", " << it->second << '\n';
            // cout << "next : " << next->first << ", " << next->second << '\n';
            while (it->second >= next->first - 1 && next != sp.end()) {
                // cout << "before : " << it->first << ", is : " << it->second << '\n';
                // cout << "before : " << next->first << ", is : " << next->second << '\n';
                int val1 = it->first;
                int val2 = max(it->second, next->second);
                sp.erase(*next);
                sp.erase(*it);
                auto neww = sp.insert({ val1, val2 }).first;
                it = neww;
                next = neww; next++;
                // cout << "after : " << it->first << ", is : " << it->second << '\n';
                // cout << "after : " << next->first << ", is : " << next->second << '\n';
            }
        } else if (opr == 2) {
            cout << sp.size() << '\n';
        }
    }
    return 0;
}


// #include <iostream>
// #include <set>
// #include <utility>
// #include <cmath>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n;
//     set<pair<int, int>> s;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int action;
//         cin >> action;
//         if (action == 1) {
//             int a, b;
//             cin >> a >> b;
//             auto it = (s.insert({ a,b })).first;
//             if (it != s.begin()) {
//                 auto it1 = it;
//                 --it1;
//                 if (it->first - 1 <= it1->second) {
//                     a = it1->first;
//                     b = max(it->second, it1->second);
//                     s.erase(*it);
//                     s.erase(*it1);
//                     it = (s.insert({ a,b })).first;
//                 }
//             }
//             auto it2 = it;
//             it2++;
//             while (it->second >= it2->first - 1 && it2 != s.end()) {
//                 a = it->first;
//                 b = max(it2->second, it->second);
//                 s.erase(*it);
//                 s.erase(*it2);
//                 it = (s.insert({ a,b })).first;
//                 it2 = it;
//                 it2++;
//             }
//         } else if (action == 2) {
//             cout << s.size() << "\n";
//         }
//     }


//     return 0;
// }
