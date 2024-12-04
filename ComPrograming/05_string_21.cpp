#include <bits/stdc++.h>
using namespace std;

//!bug???
// int main() {
//     string s; cin >> s;
//     vector<string> ss;

//     //calculate
//     string temp = "";
//     for (int i = 0;i < s.size();i++) {
//         if (('A' <= s[i] && s[i] <= 'Z') || //case upper case
//             //
//             !('0' <= temp[temp.size() - 1] && temp[temp.size() - 1] <= '9') && ('0' <= s[i] && s[i] <= '9') //
//             !('0' <= temp[temp.size() - 1] && temp[temp.size() - 1] <= '9') && ('0' <= s[i] && s[i] <= '9') //
//             ) {
//             ss.push_back(temp);
//             temp = s[i];
//         } else {
//             temp += s[i];
//         }
//     }
//     ss.push_back(temp);


//     //out put
//     if (ss[0] == "") ss.erase(ss.begin());
//     for (int i = 0;i < ss.size();i++) {
//         cout << ss[i];
//         if (i != ss.size() - 1) { cout << ", "; }
//     }

//     return 0;
// }

//!sol1
int main() {
    string s; cin >> s;
    vector<string> ss;

    //calculate
    string temp = "";
    for(int i = 0;i < s.size();i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            ss.push_back(temp);
            temp = s[i];
        } 
        else if (!('0' <= temp[temp.size() - 1] && temp[temp.size() - 1] <= '9') &&
            ('0' <= s[i] && s[i] <= '9')) {
            ss.push_back(temp);
            temp = s[i];
        }
        else if (!('0' <= s[i] && s[i] <= '9') &&
            ('0' <= temp[temp.size() - 1] && temp[temp.size() - 1] <= '9')) {
            ss.push_back(temp);
            temp = s[i];
        } 
        else {
            temp += s[i];
        }
    }
    ss.push_back(temp);


    //out put
    if(ss[0] == "") ss.erase(ss.begin());
    for(int i = 0;i < ss.size();i++) {
        cout << ss[i];
        if(i != ss.size() - 1) { cout << ", "; }
    }

    return 0;
}