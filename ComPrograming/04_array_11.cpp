#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    vector<bool> ck(10, false);
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            ck[c - '0'] = true;
        }
    }

    string ans = "";
    for(int i = 0;i <= 9;i++){
        if(!ck[i]) { ans += to_string(i); }
    }
    //cout << "ans.size() : " << ans.size() << endl;
    if(ans.size() == 0) { cout << "None"; return 0;}
    for(int i = 0;i < ans.size();i++){
        cout << ans[i];
        if(i != ans.size() - 1) { cout << ","; }
    }
}