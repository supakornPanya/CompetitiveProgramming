#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, name;
    map<string, vector<string>> m;
    vector<string> order;
    set<string> s;
    while(cin >> name >> t) {
        m[t].push_back(name);
        if(s.find(t) == s.end()){
            order.push_back(t);
            s.insert(t);
        }
    }

    for(int i = 0;i < order.size();i++) {
        cout << order[i] << ": ";
        for(int j = 0;j < m[order[i]].size();j++) {
            cout << m[order[i]][j] << " ";
        }
        cout << endl;
    }
}