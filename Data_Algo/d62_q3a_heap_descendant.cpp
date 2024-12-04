#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void call(int size, int parent) {
    if (parent > size) return;
    int l = (parent * 2) + 1;
    if (l < size) {
        ans.push_back(l);
        call(size, l);
    }
    int r = (parent * 2) + 2;
    if (r < size) {
        ans.push_back(r);
        call(size, r);
    }
}

int main() {
    int n, a; cin >> n >> a;
    ans.push_back(a);
    call(n, a);

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (size_t i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
}