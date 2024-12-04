#include <bits/stdc++.h>
using namespace std;

int main() {
    bool zigzag;
    int minZig = INT_MAX, minZag = INT_MAX, maxZig = INT_MIN, maxZag = INT_MIN, round = 0;
    while (true) {
        int x, y; cin >> x;
        if (x == -998) { zigzag = true; break; }
        if (x == -999) { zigzag = false; break; }
        cin >> y;
        if(round % 2 == 0){
            if(x < minZig) { minZig = x; }
            if(x > maxZag) { maxZag = x; }
            if(y > maxZig) { maxZig = y; }
            if(y < minZag) { minZag = y; }
        } else {
            if (x > maxZig) { maxZig = x; }
            if (x < minZag) { minZag = x; }
            if (y < minZig) { minZig = y; }
            if (y > maxZag) { maxZag = y; }
        }
        round++;
    }

    if(zigzag) { cout << minZig << " " << maxZig; }
    else { cout << minZag << " " << maxZag; }

    return 0;
}