#include <bits/stdc++.h>
using namespace std;

int zeroTo99(int now, string s, int n, vector<string>& v) {
    int num = (n == 1) ? int(s[now] - '0') * 10 + int(s[now + 1] - '0') : int(s[now] - '0');
    if (0 <= num && num <= 20) cout << v[num];
    if (21 <= num && num <= 99) cout << v[(num / 10) * 10] << v[num % 10];
    return (n == 1) ? now + 2 : now + 1;
}

int hundred(int now, string s, vector<string>& v) {
    if (s[now] != '0')cout << v[int(s[now] - '0')] << v[100];
    return now + 1;
}

int main() {
    vector<string> v(101);
    v[0] = ""; v[1] = "one "; v[2] = "two "; v[3] = "three "; v[4] = "four ";
    v[5] = "five "; v[6] = "six "; v[7] = "seven "; v[8] = "eight "; v[9] = "nine ";
    v[10] = "ten "; v[11] = "eleven "; v[12] = "twelve "; v[13] = "thirteen "; v[14] = "fourteen ";
    v[15] = "fifteen "; v[16] = "sixteen "; v[17] = "seventeen "; v[18] = "eighteen "; v[19] = "nineteen ";
    v[20] = "twenty "; v[30] = "thirty "; v[40] = "forty ";
    v[50] = "fifty "; v[60] = "sixty "; v[70] = "seventy "; v[80] = "eighty "; v[90] = "ninety ";
    v[100] = "hundred ";

    string s; cin >> s;
    int now = 0, n = s.size();

    //trillion
    if (n - now == 15) { now = hundred(now, s, v); }
    if (n - now >= 13) { now = zeroTo99(now, s, n - now - 13, v); }
    if (n >= 13 && (s[now - 1] != '0' || s[now - 2] != '0' || s[now - 3] != '0')) { cout << "trillion "; } //in case 000
    //billion
    if (n - now == 12) { now = hundred(now, s, v); }
    if (n - now >= 10) { now = zeroTo99(now, s, n - now - 10, v); }
    if (n >= 10 && (s[now - 1] != '0' || s[now - 2] != '0' || s[now - 3] != '0')) { cout << "billion "; } //in case 000
    //million
    if (n - now == 9) { now = hundred(now, s, v); }
    if (n - now >= 7) { now = zeroTo99(now, s, n - now - 7, v); }
    if (n >= 7 && (s[now - 1] != '0' || s[now - 2] != '0' || s[now - 3] != '0')) { cout << "million "; } //in case 000
    //thousand
    if (n - now == 6) { now = hundred(now, s, v); }
    if (n - now >= 4) { now = zeroTo99(now, s, n - now - 4, v); }
    if (n >= 4 && (s[now - 1] != '0' || s[now - 2] != '0' || s[now - 3] != '0')) { cout << "thousand "; } //in case 000
    //hundred
    if (n - now == 3) { now = hundred(now, s, v); }
    if (n - now == 2) { now = zeroTo99(now, s, 1, v); }
    if (n == 1 && s[0] == '0') cout << "zero";
    else if (n - now == 1) { cout << v[int(s[now] - '0')]; }

    return 0;
}