#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    int r = 0;

    //rounds 1 of input
    int n; cin >> n;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        if (r % 2 == 0) dq.push_back(x);
        else dq.push_front(x);
        r++;
    }

    //rounds 2 of input
    string s; cin.ignore(); getline(cin, s);
    string temp = "";
    for (int i = 0;i < s.size();i++) {
        if (s[i] == ' ') {
            if (r % 2 == 0) dq.push_back(stoi(temp));
            else dq.push_front(stoi(temp));
            temp = ""; r++;
        } else {
            temp += s[i];
        }
    }
    if (r % 2 == 0 && temp != "") { dq.push_back(stoi(temp)); r++; } 
    else if (temp != "") { dq.push_front(stoi(temp)); r++; }

    //rounds 3 of input
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        if (r % 2 == 0) dq.push_back(x);
        else dq.push_front(x);
        r++;
    }

    cout << "[";
    while (!dq.empty()) {
        cout << dq.front(); dq.pop_front();
        if (dq.size() != 0) { cout << ", "; }
    }
    cout << "]";

    return 0;
}