#include <bits/stdc++.h>
using namespace std;

int main() {
    int h; cin >> h;
    int l = h, r = h;
    for (int i = 1;i < h;i++) {
        for (int j = 1;j <= (2 * h) - 1;j++) {
            if (j == l || j == r) { cout << "*"; }
            else if(j < r) { cout << "."; }
            else break;
        }
        cout << endl;
        l--; r++;
    }
    for (int i = 1;i <= (2 * h) - 1;i++) { cout << "*"; }
}