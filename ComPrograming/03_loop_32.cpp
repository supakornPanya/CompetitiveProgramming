#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    cin.ignore();
    while (q--) {
        string s; getline(cin, s);
        //split ' '
        vector<char> v;
        for (char c : s) {
            if (c != ' ') { v.push_back(c); }
        }

        // cout << "v : "; for(char c : v) { cout << c << ", "; } cout << endl;

        //loop in input
        if (v[0] != 'R') { cout << "WRONG_INPUT" << endl; continue; }
        if (v[0] == 'R' && v.size() == 1) { cout << 1 << endl; continue; }

        map<char, int> m;
        m['R'] = 1, m['Y'] = 2, m['G'] = 3, m['N'] = 4, m['B'] = 5, m['P'] = 6, m['K'] = 7;
        int sum = 0, i, j;

        //loop pair of R?
        for (i = 1;i < v.size();i += 2) {
            if (v[i - 1] == 'R' && v[i] != 'R') {
                sum += m[v[i - 1]]; sum += m[v[i]];
            } else {
                break;
            }
        }
        i -= 2;
        // cout << "i : " << i << endl;

        //loop next of pair R?
        if(i + 1 < v.size()) sum += m[v[i + 1]];
        // bool wrong = false;
        bool wrong = (i + 1 > v.size() - 1 || v[i + 1] == 'Y' || v[i + 1] == 'R')? false : true;
        for(j = i + 2;j < v.size();j++) {
            if(m[v[j]] - m[v[j - 1]] != 1) {
                wrong = true;
                break;
            } else {
                sum += m[v[j]];
            }
        }
        if (wrong) { cout << "WRONG_INPUT" << endl; }
        else { cout << sum << endl; }
    }
}