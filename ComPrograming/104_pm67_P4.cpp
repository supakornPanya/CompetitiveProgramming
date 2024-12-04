#include <bits/stdc++.h>
using namespace std;

map<string, int> m1;

void dfs(int n, vector<vector<char>>& v1, int now, vector<char>& sol) {
    if (n == now && sol.size() == n) {
        string ans = "";
        for (char c : sol) {
            ans += c;
        }
        sort(ans.begin(), ans.end());
        if (m1.find(ans) == m1.end()) m1[ans] = 1;
        else m1[ans] += 1;
        return;
    }

    for (int i = 0;i < v1[now].size();i++) {
        sol.push_back(v1[now][i]);
        dfs(n, v1, now + 1, sol);
        sol.pop_back();
    }
}

struct A {
    int n; string s;
    bool operator < (const A& other) const {
        if (n != other.n) return n > other.n;
        return s < other.s;
    }
};

int main() {
    int n; cin >> n;
    vector<vector<char>> v1;
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        vector<char> temp;
        for (char c : s) {
            temp.push_back(c);
        }
        sort(temp.begin(), temp.end());
        v1.push_back(temp);
    }


    vector<char> sol;
    dfs(n, v1, 0, sol);
    vector<A> v2;
    for (auto it = m1.begin();it != m1.end();it++) {
        //cout << "it : " << it->second << " " << it->first << endl;
        v2.push_back({ it->second, it->first });
    }
    sort(v2.begin(), v2.end());

    int m; cin >> m;
    for (int i = 0;i < m;i++) {
        cout << v2[i].s << endl;
    }

    return 0;
}

