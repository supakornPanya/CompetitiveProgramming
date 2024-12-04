#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    
    if (s == "no parentheses") { cout << "no parentheses"; return 0;  }

    for(int i = 0;i < s.size();i++){
        if(s[i] == '(') { s[i] = '['; }
        else if (s[i] == '[') { s[i] = '('; }
        else if (s[i] == ')') { s[i] = ']'; }
        else if (s[i] == ']') { s[i] = ')'; }
    }
    cout << s;

    return 0;
}