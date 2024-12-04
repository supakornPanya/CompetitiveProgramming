#include <bits/stdc++.h>
using namespace std;

int main() {
    string t; int k; cin >> t >> k;
    char comp = t[0]; int cnt = 1; string ans = "";
    for (int i = 1;i < t.size();i++) {
        if (comp == t[i]) {
            cnt++;
        } else {
            if (cnt < k) { 
                for (int i = 0;i < cnt;i++) { 
                    ans += comp; 
                } 
                //cout << i << " ";
            }
            comp = t[i]; cnt = 1;
        }
    }
    if(cnt < k) { for(int i = 0;i < cnt;i++) { ans += comp; } }

    cout << ans;

    return 0;
}