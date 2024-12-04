#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<string>& s) {
    int A = 0, val = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == "A") {
            A++;
        } else if (s[i] == "J" || s[i] == "Q" || s[i] == "K" || s[i] == "10") {
            val += 10;
        } else {
            val += stoi(s[i]);
        }
    }
    if(A == 3) {
        if(val + 13 <= 21) val += 13;
        else if(val + 3 <= 21) val += 3;
    }
    if(A == 2) {
        if(val + 12 <= 21) val += 12;
        else if(val + 2 <= 21) val += 2;
        else val += 22;
    }
    if (A == 1) val += (val + 11 <= 21) ? 11 : 1;
    return val;
}

int main() {
    int n1,n2; cin >> n1 >> n2;
    int A1 = 0, A2 = 0;
    vector<string> s1(n1),s2(n2);

    for(int i = 0;i < n1;i++) { cin >> s1[i]; }
    int val1 = f(n1, s1);

    for (int i = 0;i < n2;i++) { cin >> s2[i]; }
    int val2 = f(n2, s2);

    if ((val1 > 21 && val2 > 21) || (val1 == val2)) {
        cout << "Draw" << endl;
    } else if((val1 > val2 && val1 <= 21) || val2 > 21) {
        cout << "A" << endl;
    } else if ((val1 < val2 && val2 <= 21) || val1 > 21) {
        cout << "B" << endl;
    }

    cout << val1 << " " << val2 << endl;
}