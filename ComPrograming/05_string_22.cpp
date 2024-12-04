#include <bits/stdc++.h>
using namespace std;

void f(string s, string t, pair<string, string>& ans, int& maxx, bool round_1) {
    for (int i = 0;i < s.size();i++) {
        int cnt = 0;
        for (int j = 0;j < min(s.size(), t.size());j++) { //compare
            if (t[j] == s[j]) cnt++;
        }
        if (cnt > maxx) { 
            ans.first = round_1 ? t : s;
            ans.second = round_1 ? s : t;
            maxx = cnt;
        }
        t = '-' + t;
    }
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    pair<string,string> ans = make_pair(s1,s2);
    int maxx = 0;
    f(s2, s1, ans, maxx, true);
    f(s1, s2, ans, maxx, false);
    cout << ans.first << endl << ans.second << endl << maxx;
}