#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    set<int> s;
    while(cin >> n) {
        cnt++;
        // cout << "n : " << n << endl;
        if(s.find(n) != s.end()) {
            cout << cnt; return 0;
        }
        s.insert(n);
    }
    cout << "-1";
}