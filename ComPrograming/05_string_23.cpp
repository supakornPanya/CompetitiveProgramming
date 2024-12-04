#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int round; cin >> round;

    int n1 = int(s[0] - '0'); //1 st number
    char c1 = s[1], c2 = s[2]; //2 char
    int n2 = int(s[4] - '0') * 100 + int(s[5] - '0') * 10 + int(s[6] - '0'); //convert to int 3 digit

    bool cnt = false;
    //base 10 of number
    int prev = n2;
    n2 = (n2 + round) % 1000; //find value n2 of 3 digit
    string n = to_string(n2 % 1000); while (n.size() != 3) { n = '0' + n; } //in case length of n is shorter than 3
    round = (prev + round) / 1000; //ทดหลักถัดไป : sum(all)
    // cout << "round1 : " << round << endl;
    
    //base 26 of char
    prev = int(c2 - 'A');
    c2 = char(((int(c2 - 'A') + (round % 26)) % 26) + 'A'); //find new c2
    round = (prev + round) / 26;//ทดหลักถัดไป : sum(all)
    // cout << "round2.1 : " << round << endl;
    prev = int(c1 - 'A');
    c1 = char(((int(c1 - 'A') + (round % 26)) % 26) + 'A'); //find new c1
    round = (prev + round) / 26;//ทดหลักถัดไป : sum(all)
    // cout << "round2.2 : " << round << endl;

    //base 10 of 1st number
    n1 = n1 + (round % 10);
    // cout << "round3 : " << round << endl;

    //out put
    cout << n1 << c1 << c2 << "-" << n;

    return 0;
}

// ((now + round) %26) + 'a'
// (newChar %26) + 'a'
// (newChar is not overflow a-z) + 'a'
// form int to char