#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    if (s.size() == 10 && ((s[0] == '0' && s[1] == '6') 
        || (s[0] == '0' && s[1] == '8') 
        || (s[0] == '0' && s[1] == '9'))) {
        cout << "Mobile number";
    } else {
        cout << "Not a mobile number";
    }
}