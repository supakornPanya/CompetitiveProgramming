#include <bits/stdc++.h>
using namespace std;

int main() {
    int y; cin >> y;
    y = (y - 543) % 100; //common era in 2 digit
    cout << (y + (y / 4) + 11) % 7;
}