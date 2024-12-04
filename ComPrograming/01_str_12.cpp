#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> v = { "", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    string s; cin >> s;

    int day = (int(s[0] - '0') * 10) + (int(s[1] - '0'));
    int month = (int(s[3] - '0') * 10) + (int(s[4] - '0'));
    int year = (int(s[6] - '0') * 1000) + (int(s[7] - '0') * 100) + (int(s[8] - '0') * 10) + int(s[9] - '0');

    cout << v[month] << " " << day << ", " << year - 543;

    return 0;
}