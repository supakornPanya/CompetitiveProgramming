#include <bits/stdc++.h>
using namespace std;


// O(n^2) using stack to reverse, write all funtion by my self
/*
class Solution {
public:
    int reverse(int x) {
        stack<int> SI; //stack int
        bool flagM, flag0 = false;
        if (0 <= x && x < 10) { return x; }
        if (x < 0) { flagM = true; }
        while (x) {
            int temp = x % 10;
            if (temp != 0) { flag0 = true; }
            if (!flag0 && temp == 0) { x /= 10; continue; }
            SI.push(temp);
            x /= 10;
        }
        int j = 1; long long ans = 0;
        while (!SI.empty()) {
            int a = SI.top(); SI.pop();
            ans += a * j;
            j *= 10;
        }
        if (ans > INT_MAX || ans < (INT_MAX * -1 - 1)) { return 0; }
        if (!flagM) { return ans *= -1; } else { return ans; }
    }
};
*/

//fastest but it use library to convert int to string and string to int.
class Solution {
public:
    int reverse(int x) {
        bool flagM = false;
        if (0 <= x && x <= 9) { return x; }
        if (x < 0) { flagM = true; }
        string s = to_string(x);
        auto l = s.begin(), r = s.end() - 1;
        while (l < r) {
            swap(*l, *r);
            l++; r--;
        }
        long long ans = stoll(s);
        if (ans > INT_MAX || ans < (INT_MAX * -1 - 1)) { return 0; }
        if (flagM) { return int(ans) * -1; } else { return int(ans); }
    }
};

int main() {
    Solution sol;
    int x = -2147483648;
    int ans = sol.reverse(x);
    cout << ans;
}