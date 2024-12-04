#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ans;
    int n; cin >> n;
    
    while(n != 1) {
        if(n % 2 == 0) {
            ans.push_back(n);
            n = n / 2;
        } else {
            ans.push_back(n);
            n = (3 * n) + 1;
        }
    }
    ans.push_back(1);

    if(ans.size() <= 15) {
        for(int i = 0;i < ans.size();i++) {
            cout << ans[i];
            if(i != ans.size() - 1) cout << "->";
        }
    } else {
        for (int i = ans.size() - 15;i < ans.size();i++) {
            cout << ans[i];
            if (i != ans.size() - 1) cout << "->";
        }
    }

    return 0;
}