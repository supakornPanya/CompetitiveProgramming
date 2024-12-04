#include <bits/stdc++.h>
using namespace std;

int main() {
    string code; getline(cin, code);
    map<string, string> m;
    m["0000"] = "0"; m["0"] = "0000";
    m["0001"] = "1"; m["1"] = "0001";
    m["0010"] = "2"; m["2"] = "0010";
    m["0011"] = "3"; m["3"] = "0011";
    m["0100"] = "4"; m["4"] = "0100";
    m["0101"] = "5"; m["5"] = "0101";
    m["0110"] = "6"; m["6"] = "0110";
    m["0111"] = "7"; m["7"] = "0111";
    m["1000"] = "8"; m["8"] = "1000";
    m["1001"] = "9"; m["9"] = "1001";
    m["1010"] = "-"; m["-"] = "1010";
    m["1011"] = ","; m[","] = "1011";

    char opr;
    while (cin >> opr) {
        string s; cin.ignore(); getline(cin, s);
        // cout << "s : " << s << endl;
        // cout << "-------------------" << endl;

        //operator E
        if (opr == 'E') {
            int idxCode = 0;
            for (int i = 0;i < s.size();i++) { //loop code each char

                string key = to_string(s[i] - '0');
                key = (s[i] == '-')? "-": key;
                key = (s[i] == ',') ? "," : key;
                string pas = m[key];
                // cout << "key : " << key << ", pas : " << pas << endl; 
                for (int j = 0;j < 4;j++) { //loop code upper/lower case.
                    char c = code[idxCode % code.size()]; //template for create code
                    // cout << "c : " << c << ", ";

                    if (islower(c)) {
                        char ans = (pas[j] == '1') ? c : char((c - 'a') + 'A');
                        cout << ans;
                        idxCode++;
                    } else if (isupper(c)) {
                        char ans = (pas[j] == '0') ? c : char((c - 'A') + 'a');
                        cout << ans;
                        idxCode++;
                    } else {
                        cout << c;
                        idxCode++; j--;
                    }
                }
            }

            cout << endl;
        }
        //operator D
        if (opr == 'D') {
            string pas = "";
            for (int i = 0;i < s.size();i++) {
                if (pas.size() == 4) {
                    cout << m[pas];
                    pas = "";
                }
                if ('a' <= s[i] && s[i] <= 'z') pas += '1';
                if ('A' <= s[i] && s[i] <= 'Z') pas += '0';
            }
            cout << m[pas]; //stuck last out put
            cout << endl;
        }
    }
}