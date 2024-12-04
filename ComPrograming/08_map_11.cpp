#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,string> m;
    int n; cin >> n;
    while(n--) {
        string s1, s2; cin >> s1 >> s2;
        m[s1] = s2; m[s2] = s1;
    }

    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        if(m.find(s) == m.end()) { cout << "Not found" << endl; }
        else { cout << m[s] << endl; }
    }

    return 0;
}