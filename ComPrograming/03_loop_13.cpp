#include <bits/stdc++.h>
using namespace std;

//!sol with comment
int main() {
    string s, ss; getline(cin, s); getline(cin, ss);
    int cnt = 0;
    cout << s << " -> " << s.size() << endl;
    cout << ss << " -> " << ss.size() << endl;
    for (int i = 0;i < ss.size();i++) {

        cout << ss[i] << " ";

        if (s[0] == ss[i]) {

            cout << endl << "case------>" << endl;

            bool ck = true;
            //check all string s
            cout << "loop ? : " << endl;
            for (int j = 0;j < s.size() && i + j < ss.size();j++) {
                if (s[j] != ss[i + j]) {
                    ck = false;
                    cout << "in loop" << endl;
                    break;
                }
            }
            cout << endl;

            //lower bound is " ( ) , . ' ???
            cout << "lower bound ?? : " << endl;
            if (!((i - 1 == -1) || (ss[i - 1] == '"' || ss[i - 1] == '('
                || ss[i - 1] == ')' || ss[i - 1] == ',' || ss[i - 1] == '.'
                || ss[i - 1] - '0' == -9 || ss[i - 1] == ' '))) {
                cout << "in case 1" << endl;
                ck = false;
            }

            //upper bound is " ( ) , . ' ???
            int n = s.size();
            cout << "upper bound ?? : " << endl;
            if (!((i + n == ss.size()) || (ss[i + n] == '"' || ss[i + n] == '('
                || ss[i + n] == ')' || ss[i + n] == ',' || ss[i + n] == '.'
                || ss[i + n] - '0' == -9 || ss[i + n] == ' '))) {
                cout << "in case 2" << endl;
                ck = false;
            }

            if (ck) { cnt++; }
        }
    }

    cout << cnt;

    return 0;
}


//!sol with out comment
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s, ss; getline(cin, s); getline(cin, ss);
//     int cnt = 0;
//     for (int i = 0;i < ss.size();i++) {
//         if (s[0] == ss[i]) {

//             bool ck = true;
//             //check all string s
//             for (int j = 0;j < s.size() && i + j < ss.size();j++) {
//                 if (s[j] != ss[i + j]) {
//                     ck = false;
//                     break;
//                 }
//             }

//             //lower bound is " ( ) , . ' ???
//             if (!((i - 1 == -1) || (ss[i - 1] == '"' || ss[i - 1] == '('
//                 || ss[i - 1] == ')' || ss[i - 1] == ',' || ss[i - 1] == '.'
//                 || ss[i - 1] - '0' == -9 || ss[i - 1] == ' '))) {
//                 ck = false;
//             }
//             //upper bound is " ( ) , . ' ???
//             int n = s.size();
//             if (!((i + n == ss.size()) || (ss[i + n] == '"' || ss[i + n] == '('
//                 || ss[i + n] == ')' || ss[i + n] == ',' || ss[i + n] == '.'
//                 || ss[i + n] - '0' == -9 || ss[i + n] == ' '))) {
//                 ck = false;
//             }
//             if (ck) { cnt++; }
//         }
//     }

//     cout << cnt;

//     return 0;
// }