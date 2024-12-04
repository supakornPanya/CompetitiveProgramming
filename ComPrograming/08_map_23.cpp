#include <bits/stdc++.h>
using namespace std;

struct A {
    string t; //type of music
    int m, s; //minute, second
    bool operator < (const A& other) const {
        if(m != other.m) return m > other.m;
        if(s != other.s) return s > other.s;
        return t < other.t;
    }
};

int main() {
    vector<A> ans;
    map<string, int> m; //key:type, value:index in vector

    //input
    string s;
    while(getline(cin, s)) {
        //split string s by ' ', namesSong nameSong type time
        string temp = "", typee;
        for(char c : s) {
            if(c == ' ') {
                typee = temp;
                temp = "";
            } else {    
                temp += c;
            }
        }
        //split string time by ':'
        string time = temp;
        int minute, second;
        for(char c : time) {
            if(c == ':') {
                minute = stoi(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        second = stoi(temp);
        //push all data to vector ans
        if(m.find(typee) == m.end()) {
            ans.push_back({ typee, minute, second });
            m[typee] = ans.size() - 1;
        } else {
            ans[m[typee]].m += minute;
            ans[m[typee]].s += second;
        }
        // cout << "type : " << typee << ", m : " << minute << ", s : " << second << endl;
    }

    for(int i = 0;i < ans.size();i++) {
        // cout << "t : " << ans[i].t << ", m : " << ans[i].m << ", s : " << ans[i].s << endl;
        ans[i].m += (ans[i].s) / 60;
        ans[i].s = ans[i].s % 60;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0;i < ans.size() && i < 3;i++) {
        cout << ans[i].t << " --> " << ans[i].m << ":" << ans[i].s << endl;
    }

    return 0;
}