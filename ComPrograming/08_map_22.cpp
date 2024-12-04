#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, double> m;

    int n; cin >> n;
    for(int i = 0;i < n;i++) {
        string t; double val; cin >> t >> val;
        m[t] = val;
    }

    // cout << "m : " << endl;
    // for(auto x : m) { cout << "key : " << x.first << ", value : " << x.second << endl; }

    //get value
    int val; cin >> val;

    //split each question
    vector<string> q;
    string temp = "", s; cin.ignore(); getline(cin, s);
    for(char c : s) {
        if (c == ' ') {
            q.push_back(temp); temp = "";
        } else {
            temp += c;
        }
    }
    q.push_back(temp);

    // cout << "q : " << endl; for(string s : q) { cout <<"s : " << s << endl; }

    //loop each exchange
    string prev = q[0], now;
    for(int i = 0;i < q.size();i++) {
        now = q[i];
        // cout << "i : " << i << ", now : " << now << ", prev : " << prev << endl;
        if(prev == "THB" && now == "THB") {
            cout << val << " " << now;
            // cout << "(THB,THB)";
            if(i != q.size() - 1) cout << " -> ";
        }
        else if(prev == "THB" && now != "THB") { // THB to other
            val = int(val / m[now]);
            cout << val << " " << now;
            // cout << "(THB,other)";
            if (i != q.size() - 1) cout << " -> ";
        }
        else if (prev != "THB" && now == "THB") { //other to THB
            val = int(val * m[prev]);
            cout << val << " " << now;
            // cout << "(other,THB) m[now] : " << m[now] << ", now : " << now;
            if (i != q.size() - 1) cout << " -> ";
        }   
        else { //other1 and other2
            val = int(val * m[prev] / m[now]);
            cout << val << " " << now;
            // cout << "(other,other)";
            if (i != q.size() - 1) cout << " -> ";
        }
        prev = now;
    }

    return 0;
}