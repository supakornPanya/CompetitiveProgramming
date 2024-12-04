#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<char> ms1, ms2;
    string s1, s2; getline(cin, s1);
    for (char c : s1) {
        if (c != ' ') {
            ms1.insert(char(tolower(c))); ms1.insert(char(toupper(c)));
        }
    }
    getline(cin, s2);
    for (char c : s2) {
        if (c != ' ') {
            ms2.insert(char(tolower(c))); ms2.insert(char(toupper(c)));
        }
    }
    if(ms1 == ms2) cout << "YES";
    else cout << "NO";

    return 0;
}