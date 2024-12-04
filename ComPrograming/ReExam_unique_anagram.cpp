#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set<string> ans;
    while(cin >> s) {
        sort(s.begin(), s.end());
        ans.insert(s);
    }
    cout << ans.size();
    return 0;    
}