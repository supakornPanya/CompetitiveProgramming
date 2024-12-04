#include <bits/stdc++.h>
using namespace std;

//! if 8 case??????
int main() {
    string a, b, c; cin >> a >> b >> c;

    //? c=="0" && b!="0" -> lower="0*b.size()" -> bug
    if (a != "0" && b != "0" && c == "0") {
        int gcd = __gcd(stoi(a + b), int(pow(10, b.size())));
        cout << stoi(a + b) / gcd << " / " << pow(10, b.size()) / gcd;
    }

    string t = "";
    if (c != "0") {
        for (int i = 0;i < c.size();i++) { t += '9'; }
    }
    if (b != "0") {
        for (int i = 0;i < b.size();i++) { t += '0'; }
    }
    int lower = (t.size() == 0) ? 1 : stoi(t);
    if (c == "0") c = ""; //in case c=0 -> b+"0" != b+""
    int upper = stoi(b + c) - stoi(b);
    cout << "before upper : " << upper << endl;
    upper += stoi(a) * lower;

    int gcd = __gcd(upper, lower);

    cout << "gcd : " << gcd << endl;
    cout << "upper : " << upper << ", lower : " << lower << endl;

    cout << upper / gcd << " / " << lower / gcd;

    return 0;
}