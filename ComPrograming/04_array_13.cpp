#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    int x1 = INT_MAX, x2; cin >> x2; 
    for(int i = 1;i < n;i++) { //consider index 0 to n - 2
        int x3; cin >> x3;
        if(x1 < x2 && x2 > x3) cnt++;
        // if (x1 < x2 && x2 > x3) cout << "i : " << i << endl;
        x1 = x2; x2 = x3;
    }
    cout << cnt;

    return 0;
}