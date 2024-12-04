#include <bits/stdc++.h>
using namespace std;

bool correct;
int check(const vector<bool>& v, int l, int r) {
    if (l - r == 0) {
        return (v[l] == true) ? 1 : 0;
    }
    int mid = (l + r) / 2;
    int ll = check(v, l, mid);
    int rr = check(v, mid + 1, r);
    // cout << "ll: " << ll << ", rr: " << r << '\n';
    if(abs(ll - rr) > 1) correct = false;
    return ll + rr;
}

int main() {
    int q, k; cin >> q >> k;
    while (q--) {
        vector<bool> v;
        for (int i = 0;i < (1 << k);i++) {
            bool x; cin >> x;
            v.push_back(x);
        }
        correct = true;
        check(v, 0, v.size() - 1);
        if(correct) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}