#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int one = 0, two = 0, three = 0;
    vector<int> vec(n);
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        vec[i] = x;
        if (x == 1) one++;
        else if (x == 2) two++;
        else if (x == 3) three++;
    }

    int ans = 0;
    int _2in1 = 0, _3in1 = 0;
    int _1in2 = 0, _3in2 = 0;
    int _1in3 = 0, _2in3 = 0;
    for (int i = 0;i < vec.size();i++) {
        if(0 <= i && i < one) {
            if(vec[i] == 2) _2in1++;
            else if (vec[i] == 3) _3in1++;
        } else if (one <= i && i < one + two) {
            if (vec[i] == 1) _1in2++;
            else if (vec[i] == 3) _3in2++;
        } else if (one + two <= i) {
            if (vec[i] == 1) _1in3++;
            else if (vec[i] == 2) _2in3++;
        }
    }
    ans += min(_3in1, _1in3);
    ans += (_1in2 + _3in2);
    cout << ans;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n; cin >> n;
//     int one = 0, two = 0;
//     vector<int> vec(n);
//     for (int i = 0;i < n;i++) {
//         int x; cin >> x;
//         vec[i] = x;
//         if (x == 1) one++;
//         else if (x == 2) two++;
//     }

//     int ans = 0;
//     int i1 = 0, i2 = two, i3 = one + two;
//     // cout << one << ", " << two << '\n';
//     // cout << i1 << ", " << i2 << ", " << i3 << '\n';
//     for (int i = 0;i < vec.size();i++) {
//         if (vec[i] == 1 && !(0 <= i && i < one)) {
//             while (vec[i1] == 1) i1++; // find position should be swap
//             //find 1 that out of range
//             int idx;
//             for(idx = one;idx < vec.size();idx++) {
//                 if(vec[idx] == 1) break;
//             }
//             swap(vec[i1], vec[i]);
//             ans++;
//         } else if (vec[i] == 2 && !(one <= i && i < one + two)) {
//             while (vec[i2] == 1) i2++;
//             swap(vec[i2], vec[i]);
//             ans++;
//         } else if (vec[i] == 3 && !(one + two <= i && i < vec.size())) {
//             while (vec[i3] == 3) i3++;
//             swap(vec[i1 + i2], vec[i]);
//             ans++;
//         }
//     }
//     cout << ans;
// }