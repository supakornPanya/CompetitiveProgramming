#include <bits/stdc++.h>
using namespace std;

string dec2hex(int d, vector<string>& v) {
    if (d < 16){ 
        return v[d];
    }
    else {
        return dec2hex(d / 16, v) + dec2hex(d % 16, v);
    }
}

int main() {
    vector<string> v{ "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    int d;
    while (cin >> d) {
        cout << d << " -> " << dec2hex(d, v) << endl;
    }
    return 0;
}