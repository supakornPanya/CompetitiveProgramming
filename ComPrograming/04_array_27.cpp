#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int minZig = INT_MAX, minZag = INT_MAX, maxZig = INT_MIN, maxZag = INT_MIN;
    for(int i = 0;i < n;i++) {
        int x, y; cin >> x >> y;
        if(i%2 == 0) {
            minZig = min(minZig, x);
            maxZig = max(maxZig, y);
            maxZag = max(maxZag, x);
            minZag = min(minZag, y);
        } else {
            minZig = min(minZig, y);
            maxZig = max(maxZig, x);
            maxZag = max(maxZag, y);
            minZag = min(minZag, x);
        }
    }

    string opr; cin >> opr;
    if(opr == "Zig-Zag") {
        cout << minZig << " " << maxZig;
    } else {
        cout << minZag << " " << maxZag;
    }
}