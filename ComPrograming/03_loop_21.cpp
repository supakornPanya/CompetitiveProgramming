#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        string s; cin >> s;
        if(s == "") break;
        //1:upper case, 2:lower case, 3:number, 4:extra 
        bool c1 = false, c2 = false, c3 = false, c4 = false;
        //1:length >= 12, 2:length >= 8
        bool l1 = (s.size() >= 12) ? true : false;
        bool l2 = (s.size() >= 8) ? true : false;

        for (char c : s) {
            if ('A' <= c && c <= 'Z') { c1 = true; }
            else if ('a' <= c && c <= 'z') { c2 = true; }
            else if ('0' <= c && c <= '9') { c3 = true; }
            else { c4 = true; }
        }

        if (l1 && c1 && c2 && c3 && c4) { cout << ">> strong" << endl; } 
        else if (l2 && c1 && c2 && c3) { cout << ">> weak" << endl; } 
        else { cout << ">> invalid" << endl; }
    }

    return 0;
}