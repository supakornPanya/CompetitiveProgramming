#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int x1 = s[0] - '0'; vector<int> v1(2, 0);
    int x2 = s[1] - '0'; vector<int> v2(4, 0);
    int x3 = s[3] - '0'; vector<int> v3(3, 0);
    int x4 = s[4] - '0'; vector<int> v4(4, 0);
    int x5 = s[6] - '0'; vector<int> v5(3, 0);
    int x6 = s[7] - '0'; vector<int> v6(4, 0);
    //cout << "v1 : "; for(int x : v1) { cout << x << " "; } cout << endl;
    for (int i = v1.size() - 1;i >= 0;i--) {
        if (x1 >= pow(2, i)) {
            v1[i] = 1;
            x1 -= pow(2, i);
        }
    }
    for (int i = v2.size() - 1;i >= 0;i--) {
        if (x2 >= pow(2, i)) {
            v2[i] = 1;
            x2 -= pow(2, i);
        }
    }
    for (int i = v3.size() - 1;i >= 0;i--) {
        if (x3 >= pow(2, i)) {
            v3[i] = 1;
            x3 -= pow(2, i);
        }
    }
    for (int i = v4.size() - 1;i >= 0;i--) {
        if (x4 >= pow(2, i)) {
            v4[i] = 1;
            x4 -= pow(2, i);
        }
    }
    for (int i = v5.size() - 1;i >= 0;i--) {
        if (x5 >= pow(2, i)) {
            v5[i] = 1;
            x5 -= pow(2, i);
        }
    }
    for (int i = v6.size() - 1;i >= 0;i--) {
        if (x6 >= pow(2, i)) {
            v6[i] = 1;
            x6 = x6 - pow(2, i);
        }
    }

    cout << " " << v2[3] << " " << v4[3] << " " << v6[3] << endl;
    cout << " " << v2[2] << v3[2] << v4[2] << v5[2] << v6[2] << endl;
    cout << v1[1] << v2[1] << v3[1] << v4[1] << v5[1] << v6[1] << endl;
    cout << v1[0] << v2[0] << v3[0] << v4[0] << v5[0] << v6[0] << endl;
}

