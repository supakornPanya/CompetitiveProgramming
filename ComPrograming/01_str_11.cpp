#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int sum = 0, temp = 13;
    for (char c : s) {
        //cout << temp-- * int(c - '0') << endl;
        //temp++;
        sum += temp-- * int(c - '0');
    }
    sum = (11 - (sum % 11)) % 10;
    cout << s[0] << "-";
    for (int i = 1;i <= 4;i++) { cout << s[i]; } cout << "-";
    for (int i = 5;i <= 9;i++) { cout << s[i]; } cout << "-";
    for (int i = 10;i <= 11;i++) { cout << s[i]; } cout << "-";
    cout << sum;

}