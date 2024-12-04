    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        std::ios_base::sync_with_stdio(false); std::cin.tie(0);
        int n; cin >> n;
        vector<int> cnt(n, 0);
        vector<int> deg(n, 0);
        int k = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                int x; cin >> x;
                if (x == 1) cnt[i]++;
            }
            deg[cnt[i]]++;
            k = max(cnt[i], k);
        }

        for (int i = 0;i <= k;i++) {
            cout << deg[i] << " ";
        }
    }