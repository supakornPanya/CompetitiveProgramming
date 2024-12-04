#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s; s += '$';

    vector<string> v;
    int idx = 0;
    for (int i = 0;i < s.size();i++) {
        string temp = "";
        for (int j = 0;j < s.size();j++) {
            temp += s[(idx + j) % s.size()];
        }
        v.push_back(temp);
        idx++;
    }
    sort(v.begin(), v.end());

    // cout << "v : " << endl;
    // for(string ss : v) {
    //     cout << ss << endl;
    // }

    //out put
    for (int i = 0;i < v.size();i++) {
        cout << v[i][s.size() - 1];
    }

    return 0;
}