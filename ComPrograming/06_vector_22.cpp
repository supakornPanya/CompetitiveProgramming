#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    int maxLen = -1, valPrev = INT_MAX, cnt = 1, start = 0, i;
    vector<vector<int>> ans;
    for (i = 0;i < s.size();i += 2) {
        int x = int(s[i] - '0');
        if (x == valPrev) {
            // cout << "x == valPrev : " << x << ", cnt : " << cnt << endl;
            cnt++;
        } else {
            // cout << "x != valPrev : " << x << endl;
            vector<int> temp = { valPrev, start, i / 2 };
            if (cnt == maxLen) {
                // cout << " == : cnt : " << cnt << endl;
                ans.push_back(temp);
                maxLen = (i / 2) - (start);
            }
            else if (i != 0 && cnt >= maxLen) {
                // cout << " >= " << endl;
                ans.clear();
                ans.push_back(temp);
                maxLen = (i / 2) - (start);
            }
            start = i / 2;
            cnt = 1;
            valPrev = x;
        }
    }
    //??last length may be an answer
    vector<int> temp = { valPrev, start, i / 2 };
    // cout << "cnt : " << cnt << ", maxLen : " << maxLen << endl;
    if (cnt == maxLen) ans.push_back(temp);
    else if (i != 0 && cnt >= maxLen) {
        ans.clear();
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end()); //ans must be sort
    for (int i = 0;i < ans.size();i++) {
        cout << ans[i][0] << " --> x[ " << ans[i][1] << " : " << ans[i][2] << " ]" <<endl;
    }

    return 0;
}