#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i = 0;i < n;i++) {
        int x; cin >> x; 
        v.push_back(x);
    }

    bool correct = true;
    sort(v.begin(), v.end());
    for(int i = 1;i < v.size();i++) {
        if(v[i] != v[i - 1] + 1) {
            correct = false;
            break;
        }
    }

    if(correct) cout << "YES";
    else cout << "NO";
}