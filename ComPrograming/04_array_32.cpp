#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> num(n), sl(n), el(n);
    for (int i = 0;i < n;i++) {
        cin >> num[i] >> sl[i] >> el[i];
    }

    int q; cin >> q;
    while (q--) {
        int sm, em; cin >> sm >> em;
        int val = INT_MAX;
        vector<pair<int,int>> ans;
        for (int i = 0;i < n;i++) {

            // cout << "sl el : " << sl[i] << " " << el[i] << ", num : " << num[i] << endl;
            // cout << "sm em : " << sm << " " << em << endl;

            //up down || down up
            if ((sm <= em && sl[i] >= el[i]) || (sm >= em && sl[i] <= el[i])) {
                if (val >= abs(sm - el[i]) + abs(em - sm)) {
                    val = abs(sm - el[i]) + abs(em - sm); ans.push_back( {val, num[i]} );
                }
                // cout << "->1 " << abs(sm - el[i]) + abs(em - sm) << endl;
            }
            //up up || down down
            else if ((sm <= em && sl[i] <= el[i])) {
                if (sl[i] <= sm) {
                    if (el[i] < sm) {
                        if (val >= abs(sm - el[i]) + abs(em - sm)) {
                            val = abs(sm - el[i]) + abs(em - sm); ans.push_back({ val, num[i] });
                        }
                        // cout << "->2 " << abs(sm - el[i]) + abs(em - sm) << endl;
                    } else if (el[i] >= sm) {
                        if (el[i] >= em) {
                            if (val >= 0) {
                                val = 0; ans.push_back({ val, num[i] });
                            }
                            // cout << "->3 " << 0 << endl;
                        } else if (el[i] < em) {
                            if (val >= em - el[i]) {
                                val = em - el[i]; ans.push_back({ val, num[i] });
                            }
                            // cout << "->4 " << em - el[i] << endl;
                        }
                    }
                } else if (sl[i] > sm) {
                    if (val >= (el[i] - sm) + (em - sm)) {
                        val = abs(el[i] - sm) + abs(em - sm); ans.push_back({ val, num[i] });
                    }
                    // cout << "->5 " << abs(el[i] - sm) + abs(em - sm) << endl;
                }
            }
            //down down
            else if (sm >= em && sl[i] >= el[i]) {
                if (sl[i] >= sm) {
                    if (el[i] >= sm) {
                        if (val >= abs(el[i] - sm) + abs(sm - em)) {
                            val = abs(el[i] - sm) + abs(sm - em); ans.push_back({ val, num[i] });
                        }
                        // cout << "->6 " << abs(el[i] - sm) + abs(sm - em) << endl;
                    } else if (el[i] <= sm) {
                        if (el[i] <= em) {
                            if (val >= 0) {
                                val = 0; ans.push_back({ val, num[i] });
                            }
                            // cout << "->7 " << 0 << endl;
                        } else if (el[i] > em) {
                            if (val >= el[i] - em) {
                                val = el[i] - em; ans.push_back({ val, num[i] });
                            }
                            // cout << "->8 " << el[i] - em << endl;
                        }
                    }
                } else if (sl[i] < sm) {
                    if (val >= abs(sm - el[i]) + abs(sm - em)) {
                        val = abs(sm - el[i]) + abs(sm - em); ans.push_back({ val, num[i] });
                    }
                    // cout << "->9 " << abs(sm - el[i]) + abs(sm - em) << endl;
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << ">> " << ans[0].second << endl;
    }

    return 0;
}