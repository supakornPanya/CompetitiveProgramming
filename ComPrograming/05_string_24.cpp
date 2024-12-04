#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, temp = ""; getline(cin, s);
    vector<string> v;
    //separate each string by " " 
    for(char c:s) {
        if (int(c) == 32) { //index of char c == index of " "??
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += c;
    }
    v.push_back(temp);

    //swap(s[0], s[s.size() - 1]) by swap all string after vowel 
    bool found = false;
    string temp1 = "", temp2 = "", s1 = "", s2 = "";
    for(char c:v[0]) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') found = true;
        if(found) temp1 += c;
        else s1 += c;
    }
    found = false;
    for (char c : v[v.size() - 1]) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') found = true;
        if (found) temp2 += c;
        else s2 += c;
    }
    v[0] = s1 + temp2;
    v[v.size() - 1] = s2 + temp1;
    
    //out put
    for (string s : v) { cout << s << " "; }

    return 0;
}