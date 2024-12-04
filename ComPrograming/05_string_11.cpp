    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s;
        while (getline(cin, s)) {
            int rounds = 0; string temp = "", ans = "";
            for(char c : s) {
                if(!(isupper(c) || islower(c) || c == ' ' || c == '.' || c == '-' || c == ',' || int(c) == 39)) { //special charecter
                    // cout << "temp : " << temp << endl;
                    if(rounds % 2 == 1) ans += temp;
                    temp = "";
                    rounds++;
                } else {
                    temp += c;
                }
            }
            cout << ans << endl;
        }
    }