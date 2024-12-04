#include <bits/stdc++.h>
using namespace std;

set<string> ans;
void recur(string tmp, int k) {
    if(tmp.size() == k) {
        ans.insert(tmp);
        return;
    }
    recur(tmp + tmp, k);
    string reTmp;
    for(int i = tmp.size() - 1;i >= 0;i--) {
        reTmp += tmp[i];
    }
    recur(tmp + reTmp, k);
}

int main() {
    int q, k; cin >> q >> k;

    string tmp;
    tmp += "01";
    recur(tmp, k);

    while (q--) {
        string s;
        for (int i = 0;i < pow(2, k);i++) {
            char x; cin >> x;
            s += x;
        }
        if(ans.find(s) == ans.end()) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}