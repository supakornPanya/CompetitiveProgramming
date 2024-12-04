#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<pair<string,string>> q;

    int n; cin >> n; 
    for (int i = 0;i < n;i++) {
        string l, r; cin >> l >> r;
        q.push({l, r});
    }

    vector<string> ans;
    pair<string,string> node = q.front();
    ans.push_back(node.first); ans.push_back(node.second); q.pop(); 
    while(!q.empty()) {
        pair<string, string> node = q.front(); q.pop();
        string l = node.first, r = node.second;
        bool found = false;
        for(int i = 0;i < ans.size();i++) {
            if(ans[i] == l) {
                ans.insert(ans.begin() + i + 1, r);
                found = true;
                break;
            } else if(ans[i] == r) {
                ans.insert(ans.begin() + i, l);
                found = true;
                break;
            }
        }
        if (!found) {
            q.push({ l,r });
        }
    }

    for(string x : ans) {
        cout << x << " ";
    }

    return 0;
}