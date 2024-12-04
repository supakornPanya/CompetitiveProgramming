#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    vector<int> v(26, 0);
    for (char c : s) {
        char C = tolower(c);
        if ('a' <= C && C <= 'z') {
            v[C - 'a']++;
        }
    }

    for (int i = 0;i < v.size();i++) {
        if(v[i] != 0) {
            cout << char(97 + i) << " -> " << v[i] << endl;
        }
    }

    return 0;
}