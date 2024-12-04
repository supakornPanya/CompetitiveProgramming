#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<int> base(4);

vector<int> mul(const vector<int>& a, const vector<int>& b) {
    vector<int> ans(4);
    ans[0] = (((a[0] % k) * (b[0] % k)) + ((a[1] % k) * (b[2] % k))) % k;
    ans[1] = (((a[0] % k) * (b[1] % k)) + ((a[1] % k) * (b[3] % k))) % k;
    ans[2] = (((a[2] % k) * (b[0] % k)) + ((a[3] % k) * (b[2] % k))) % k;
    ans[3] = (((a[2] % k) * (b[1] % k)) + ((a[3] % k) * (b[3] % k))) % k;
    return ans;
}

vector<int> slove(int sizee) {
    if (sizee == 1) {
        return base;
    }

    if (sizee % 2 == 0) {
        vector<int> a = slove(sizee / 2);
        return mul(a, a);
    } else if (sizee % 2 != 0) {
        vector<int> a = slove(sizee / 2);
        return mul(mul(a, a), base);
    }
}

int main() {
    cin >> n >> k;
    vector<int> m(4);
    for (int i = 0;i < 4;i++) {
        int x; cin >> x;
        base[i] = x;
    }

    vector<int> ans = slove(n);

    for (int i = 0;i < 4;i++) {
        cout << ans[i] << " ";
    }
}