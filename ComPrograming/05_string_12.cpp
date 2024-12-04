#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> s1;
    while (true) {
        string s2; cin >> s2;
        if (s2 == "END") break;
        reverse(s2.begin(), s2.end());

        //add length of s1
        if (s1.size() < s2.size()) {
            while (s2.size() != s1.size()) {
                s1.push_back(0);
            }
        }

        //sum each digit 
        for (int i = 0;i < s2.size();i++) {
            s1[i] += int(s2[i] - '0');
        }
    }

    // cout << "round1 ans : " << endl;
    // for (int x : s1) { cout << x << " "; } cout << endl;

    //gradient 0 to s1.size()
    for (int i = 0;i < s1.size() - 1;i++) {
        s1[i + 1] += s1[i] / 10;
        s1[i] = s1[i] % 10;
    }

    // cout << "round2 ans : " << endl;
    // for (int x : s1) { cout << x << " "; } cout << endl;

    //gradient last index
    int idx = s1.size() - 1;
    while (true) {
        if (s1[idx] < 10) break;
        s1.push_back(s1[idx] / 10);
        s1[idx] = s1[idx] % 10;
        idx++;
    }

    //output
    //!
    for (int i = s1.size() - 1;i >= 0;i--) {
        cout << s1[i];
    }

    return 0;
}