#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int x; while(cin >> x) { v.push_back(x); }
    sort(v.begin(), v.end());
    vector<int> ans;
    int prev = INT_MAX, cnt = 0;
    for(int i = 0;i < v.size();i++) {
        if(prev != v[i]) { 
            cnt++; prev = v[i];
            ans.push_back(v[i]); 
        }
    }
    cout << cnt << endl;
    for(int i = 0;i < 10 && i < v.size();i++) {
        cout << ans[i] << " ";
    }
}