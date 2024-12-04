#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> m;

    int n; cin >> n;
    while (n--) {
        string t, c; cin >> t >> c;
        m[t] = c;
        // cout << "t : " << t << ", c : " << c << endl;
    }

    string q; cin.ignore();
    while (getline(cin, q)) {
        if (q == "q") break;
        vector<string> v; string temp = "";
        for (char c : q) {
            if (c == ' ') {
                v.push_back(temp); temp = "";
            } else {
                temp += c;
            }
        }
        v.push_back(temp);

        bool wrong = false;
        set<string> country;
        for (string s : v) {
            if (m.find(s) == m.end()) wrong = true;
            if (country.find(m[s]) != country.end()) wrong = true;
            country.insert(m[s]);
            // cout << "s : " << s << ", m[s] : " << m[s] << endl; 
        }
        if(wrong) cout << "Not OK" << endl;
        else cout << "OK" << endl;

        // cout << "v : ";
        // for (string x : v) {
        //     cout << x << " ";
        // } cout << endl;
        // cout << "q : " << q << endl;
        // cout << "--------------" <<endl;

    }

    return 0;
}