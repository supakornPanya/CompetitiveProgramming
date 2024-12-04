#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, vector<string>> m;

    //input : nameSong, nameSinger
    int n; cin >> n; cin.ignore();
    for (int i = 0;i < n;i++) {
        string s; getline(cin, s);
        string temp = "", nameSong;
        for (int j = 0;j < s.size();j++) {
            if (s[j] == ',') {
                nameSong = temp; temp = "";
                j++;
            } else {
                temp += s[j];
            }
        }
        m[nameSong].push_back(temp);
        // cout << "i : " << i << ", " << nameSong << " : " << temp << endl;
    }

    //input : nameSong
    vector<string> q;
    string s; getline(cin, s);
    // cout << "-----------------" << endl;
    // cout << "question : " << s << endl;
    string temp = "";
    for (char c : s) {
        if (c == ',') {
            q.push_back(temp); temp = "";
        } else {
            if (temp.size() == 0 && c == ' ') continue;
            temp += c;
        }
    }
    q.push_back(temp);

    // cout << "q : " << endl; for (string ss : q) { cout << ss << endl; } cout << "-----------------" << endl;

    //output
    for (int i = 0;i < q.size();i++) {
        cout << q[i] << " -> ";
        if (m[q[i]].size() == 0) { cout << "Not found" << endl; continue; }
        for(int j = 0;j < m[q[i]].size();j++) {
            cout << m[q[i]][j];
            if (j != m[q[i]].size() - 1) cout << ", ";
        }
        cout << endl;
    }
    
    return 0;
}