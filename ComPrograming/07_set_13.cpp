#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    set<string> win, lose;
    while (getline(cin, s)) {
        //split string s by ' '
        string temp = "";
        for (int i = 0;i < s.size();i++) {
            if (s[i] == ' ') {
                win.insert(temp); temp = "";
            } else {
                temp += s[i];
            }
        }
        // cout << "lose : " << temp << endl;
        lose.insert(temp);
    }

    bool ck = false;
    for (auto it = win.begin();it != win.end();it++) {
        // cout << "*it : " << *it << endl;
        if(lose.find(*it) == lose.end()) {
            cout << *it << " "; ck = true;
        }
    }
    if(!ck) cout << "None";

    return 0;
}