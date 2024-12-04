#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    //cout << s.size() << endl;
    if (s.size() >= 11) {
        cout << round(stold(s) / 10e8);
        cout << "B";
    } else if (s.size() == 10) {
        cout << round(stold(s) / 10e7)/10;
        cout << "B";
    }
    //M 
    else if (s.size() >= 8) {
        cout << round(stold(s) / 10e5);
        cout << "M";
    } else if (s.size() == 7) {
        cout << round(stold(s) / 10e4)/10;
        cout << "M";
    } 
    //K
    else if (s.size() >= 5) {
        cout << round(stold(s) / 10e2);
        cout << "K";
    } else if (s.size() == 4) {
        cout << round(stold(s) / 10e1) / 10;
        cout << "K";
    }
    //normal
    else { cout << stold(s); }


}