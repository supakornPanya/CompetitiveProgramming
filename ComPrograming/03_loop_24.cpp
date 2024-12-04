#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    char c1 = s[0]; int cnt = 1;
    for(int i = 1;i < s.size();i++) {
        if(s[i] != c1) {
            cout << c1 << " " << cnt << " ";
            c1 = s[i]; cnt = 1;
        } else {
            cnt++;
        }
    }               
    cout << c1 << " " << cnt;
}