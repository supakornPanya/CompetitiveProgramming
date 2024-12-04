#include <bits/stdc++.h>
using namespace std;

struct A {
    double d; string s;
    bool operator < (const A& other) const {
        if (d != other.d) return d > other.d;
        return s < other.s;
    }
};

int main() {
    //! can change 2 map -> map<string, pair<double, double>> = cost sum
    map<string, double> m;
    //name : value
    while (true) {
        string s; cin >> s;
        if (s == "END") break;
        double val; cin >> val;
        m[s] = val;
    }

    //name
    string name;
    map<string, double> ans;
    while (cin >> name) {
        if (m.find(name) != m.end()) {
            ans[name] += m[name];
        }
    }

    //convert map(string, double) to vector<pair<double, string>> 
    vector<A> ans2;
    for (auto x : ans) {
        ans2.push_back({ x.second, x.first });
    }
    sort(ans2.begin(), ans2.end());

    //out put
    if (ans2.size() == 0) { cout << "No Sales"; return 0; }
    auto it = ans2.begin();
    for (int i = 0;i < 3 && i < ans2.size();i++) {
        cout << ans2[i].s << " " << ans2[i].d << endl;
    }


    return 0;
}