#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    priority_queue<pair<int, string>> pq;
    while (n--) {
        string s; int x;
        cin >> s >> x;
        pq.push({ x,s });
    }
    
    cin >> n;
    while(n--){
        pair<int, string> ans = pq.top(); pq.pop();
        cout << ans.first << " " << ans.second;

        while(ans.first == pq.top().first) {
            cout << pq.top().second << " ";
            pq.pop();
        }
        
        cout << endl;
    }

    return 0;
}