#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ss; getline(cin, s); getline(cin, ss);
    if (s.size() != ss.size()) { cout << "Incomplete answer"; return 0; }

    int cnt = 0;
    for (int i = 0;i < s.size();i++) {
        if(s[i] == ss[i]) cnt++;
    }
    cout << cnt;
}