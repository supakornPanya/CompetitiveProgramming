#include <bits/stdc++.h>
using namespace std;

//brute force O(k)
// class Solution {
// public:
//     int numberOfChild(int n, int k) {
//         int t = 0, i = 0, c = 0;
//         while (c <= k) {
//             cout << i << ", ";
//             if (i == n - 1) { t++; }
//             if (c!=0 && i <= 0) { t--; }
//             if (t == 0) { i++; }
//             if (t == 1) { i--; }
//             c++;
//         }
//         if(t==0) {return i-1;}
//         else {return i+1;}
//     }
// };

//math O(1)
class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int round = k / n, remaining = k % n;
        if (round % 2 == 0) { //%2==0 go and come back -> now is go
            return remaining;
        } else { //now is come back
            return n - remaining;
        }
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    int ans = sol.numberOfChild(n, k);
    cout << "ans : " << ans;
}