#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> sumAns(n, 0);
    int prev = 0, idxPrev = -1;

    //find max of each index from left to right : O(2n)
    for (int i = 0;i < n;i++) {
        cin >> v[i];
        if (v[i] >= prev) {
            // cout << "i : " << i << ", prev : " << prev << ", idxPrev : " << idxPrev << endl;
            for (int j = idxPrev + 1;j < i;j++) {
                if(idxPrev == -1) continue;
                sumAns[j] = max(v[idxPrev] - v[j], sumAns[j]);
                // cout << sumAns[j] << endl;
            }
            prev = v[i]; idxPrev = i;
        }
    }
    // cout << endl;

    //find max of each index from right to left : O(2n)
    // cout << "right to left " << endl;
    prev = 0; idxPrev = n;
    for (int i = n - 1;i >= 0;i--) {
        if(v[i] >= prev) {
            // cout << "i : " << i << ", prev : " << prev << ", idxPrev : " << idxPrev << endl;
            for(int j = idxPrev - 1;j > i;j--) {
                if (idxPrev == n) continue;
                sumAns[j] = max(v[idxPrev] - v[j], sumAns[j]);
                // cout << sumAns[j] << " ";
            }
            prev = v[i]; idxPrev = i;
        }
    }

    //sum all column : O(n)
    int sum = 0;
    for(int x : sumAns) { sum += x; }

    cout << sum;

    return 0;
}