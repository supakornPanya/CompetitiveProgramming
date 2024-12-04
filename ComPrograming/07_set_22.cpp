#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s1; //for union
    multiset<int> ms; //for intersec
    set<int> s2; //for different

    //input
    string s; bool first = true; int cnt = 0, val;
    while (getline(cin, s)) {
        //split string s by ' '
        string temp = ""; cnt++;
        for (char c : s) {
            if (c == ' ') {
                val = stoi(temp);

                //add to set
                s1.insert(val);
                ms.insert(val);
                if (first) {
                    s2.insert(val);
                } else if (s2.find(val) != s2.end()) {
                    s2.erase(val);
                }

                // cout << val << " ";
                temp = "";
            } else {
                temp += c;
            }
        }
        val = stoi(temp);
        s1.insert(val);
        ms.insert(val);
        if (first) {
            s2.insert(val);
        } else if (s2.find(val) != s2.end()) {
            s2.erase(val);
        }

        first = false;
        // cout << val << endl;
    }

    //output
    cout << "U: ";
    if (s1.size() == 0) {
        cout << "empty set";
    } else {
        for (auto it = s1.begin();it != s1.end();it++) {
            cout << *it << " ";
        }
    }
    cout << endl;

    cout << "I: ";
    int prev = INT_MAX, cnt2 = 0;
    for (auto it = ms.begin();it != ms.end();it++) {
        if (ms.count(*it) >= cnt && *it != prev) { cout << *it << " "; cnt2++; }
        prev = *it;
    }
    if (cnt2 == 0) cout << "empty set";
    cout << endl;

    cout << "D: ";
    if (s2.size() == 0) {
        cout << "empty set";
    } else {
        for (auto it = s2.begin();it != s2.end();it++) {
            cout << *it << " ";
        }
    }
    cout << endl;

    return 0;
}