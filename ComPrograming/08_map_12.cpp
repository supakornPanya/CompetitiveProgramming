#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> m;

    int n; cin >> n;
    while(n--) {
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        string name = s1 + ' ' + s2;
        m[name] = s3; m[s3] = name;
    }

    int q; cin >> q;
    cin.ignore();
    while(q--) {
        string s; getline(cin, s);
        cout << s << " --> ";
        if(m.find(s) == m.end()) { cout << "Not found" << endl; }
        else { cout << m[s] << endl; }
    }

    return 0;
}