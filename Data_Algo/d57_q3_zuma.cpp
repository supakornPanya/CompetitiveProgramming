#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, v; cin >> n >> k >> v;
    vector<int> vec;
    for (int i = 0;i <= n;i++) {
        if (i == k) {
            vec.push_back(v);
            continue;
        }
        int x; cin >> x; vec.push_back(x);
    }

    int l = k, r = k, val = v;
    int lPass = -1, rPass = -2, range = 0;
    // for(int i = 0;i < vec.size();i++) { cout << vec[i] << " "; } cout << '\n';
    // int t = 4;
    while (true) {
        while (l >= 0 && vec[l - 1] == val) {
            l--;
        }
        while (r < vec.size() && vec[r + 1] == val) {
            r++;
        }

        range = (r - l + 1) - (rPass - lPass + 1);
        // cout << "l : " << l << ", r : " << r << ", range : " << range << '\n';
        if (range < 3) break;
        lPass = (vec[l] == val) ? l : l + 1;
        rPass = (vec[r] == val) ? r : r + 1;
        // cout << "pass : " << lPass << ", " << rPass << '\n';
        l--; r++; val = vec[l];
        if (l == 0 || r == vec.size() - 1) break;
    }

    // cout << "end : " << lPass << ", " << rPass << '\n';
    for (int i = 0;i < vec.size();i++) {
        if (lPass <= i && i <= rPass) continue;
        else {
            cout << vec[i] << " ";
        }
    }
    return 0;
}