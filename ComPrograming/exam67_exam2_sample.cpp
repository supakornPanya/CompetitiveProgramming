#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1; cin >> n1;
    map<int, set<string>> m;
    map<string, int> flag;

    for (int i = 0;i < n1;i++) {
        string s; int x; cin >> s >> x; 
        x *= -1;

        auto id = flag.find(s);
        if(id != flag.end()) {
            // cout << "s : " << id->first << ", int : " << id->second << endl;
            if (id->second > x) {
                //delete old
                set<string> old = m[id->second];
                old.erase(id->first);
                m[id->second] = old;
                //add new
                set<string> ss = m[x]; ss.insert(s);
                m[x] = ss;
                flag[s] = x;
            } else {
                continue;
            }
        } else {
            //add new
            set<string> ss = m[x]; ss.insert(s);
            m[x] = ss;
            flag[s] = x;
        }
    }

    int n2, cnt = 0; cin >> n2;
    for (auto it1 : m) {
        if(cnt == n2) break;
        if(it1.second.size() == 0) continue;
        cnt++;
        cout << it1.first * -1 << " ";
        for (auto it2 : it1.second) {
            cout << it2 << " ";
        }
        cout << endl;
    }
}