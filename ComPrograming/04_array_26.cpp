#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n * n);
    for (int i = 0;i < n * n;i++) { cin >> v[i]; }

    //find each variable : row of zero = zero, cnt of inversion = cnt, n
    int cnt = 0, zero;
    for (int i = 0;i < n * n - 1;i++) {
        if (v[i] == 0) {
            zero = i / n;
            continue;
        }
        for (int j = i + 1;j < n * n;j++) {
            if (v[j] < v[i] && v[j] != 0){
                cnt++;
                //cout << "v[i] : " << v[i] << ", v[j] : " << v[j] << endl;
            }
        }
    }

    //cout << "n : " << n << ", cnt : " << cnt << ", zero : " << zero << endl;

    //check case
    if (
        ((n % 2 == 1) && (cnt % 2 == 0)) ||
        ((n % 2 == 0) && (cnt % 2 == 1) && (zero % 2 == 0)) ||
        ((n % 2 == 0) && (cnt % 2 == 0) && (zero % 2 == 1))
        ) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}