






























#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    m["neung"] = 1, m["song"] = 2, m["sam"] = 3, m["si"] = 4, m["ha"] = 5,
    m["hok"] = 6, m["chet"] = 7, m["paet"] = 8; m["kao"] = 9; 
    m["et"] = 1; m["yi"] = 2; m["soon"] = 0;
    string s;
    while (getline(cin, s)) {
        if (s == "q") break;
        //separate string to vector<string> by ' '
        vector<string> v; string temps = "";
        for (char c : s) {
            if (c - ' ' == 0) { // this character is ' '
                v.push_back(temps); temps = "";
            } else {
                temps += c;
            }
        }
        v.push_back(temps);

        int ans = 0, temp = 1;
        for (int i = 0;i < v.size();i++) {
            if (v[i] == "lan") { //million
                ans += (temp * 1e6);
                temp=1;
            } else if (v[i] == "saen") { //hundred thousand
                ans += (temp * 1e5);
                temp = 1;
            } else if (v[i] == "muen") { //ten thousand
                ans += (temp * 1e4);
                temp = 1;
            } else if (v[i] == "phan") { //thousand
                ans += (temp * 1e3);
                temp = 1;
            } else if (v[i] == "roi") { //hundred
                ans += (temp * 1e2);
                temp = 1;
            } else if (v[i] == "sip") { //ten
                ans += (temp * 1e1);
                temp = 1;
            } else { // 1 - 9
                temp = m[v[i]];
            }
            // cout << "ans : " << ans << endl;
        }
        // cout << "last : " << v[v.size() - 1] << endl;
        if (m.find(v.back()) != m.end()) {
            ans += m[v.back()];
            // cout << "ans : " << ans << endl;
        }

        cout << ans << endl;
    }

    return 0;
}