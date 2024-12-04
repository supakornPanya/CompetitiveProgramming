//round 2 check case
#include <bits/stdc++.h>
using namespace std;

bool check(string s, int l, int r) {
    if (r - l == 1) {
        return ((s[l] == '0') && (s[r] == '1'));
    }
    int mid = (l + r) / 2;
    bool a = check(s, l, mid); //front normal
    bool b = check(s, mid + 1, r); //back

    int ll = l, midd = mid;
    while(ll <= midd) { swap(s[ll], s[midd]); ll++; midd--; }
    
    bool c = check(s, l, mid); //front reverse
    // cout << a << " " << b << " " << c << '\n';
    return ((a || c) && b);
}

int main() {
    int q, k; cin >> q >> k;
    while (q--) {
        string s = "";
        for (int i = 0;i < (1 << k);i++) {
            char x; cin >> x;
            s += x;
        }
        // cout << "s : " << s << '\n';
        bool ans = check(s, 0, pow(2,k) - 1);
        if (ans) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}


//round 1 --> 50% -----------------generate all case----------------------------
// #include <bits/stdc++.h>
// using namespace std;

// unordered_set<string> ans;
// void recur(vector<string>& prev, int k) {
//     // cout << "prev : " << prev[0] << '\n';
//     if (prev[0].size() == (1 << k)) {
//         for(const auto& str : prev) {
//             ans.insert(str);
//         }
//         return;
//     }

//     vector<string> next;
//     for(int i = 0;i < prev.size();i++) {
//         string tmp = prev[i];
//         string rtmp = prev[i];
//         reverse(rtmp.begin(), rtmp.end());
//         for(int j = 0;j < prev.size();j++) {
//             next.push_back(tmp + prev[j]);
//             next.push_back(rtmp + prev[j]);
//         }
//     }
//     recur(next, k);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int q, k; cin >> q >> k;

//     vector<string> tmp;
//     tmp.push_back("01");
//     recur(tmp, k);

//     // for (auto it = ans.begin();it != ans.end();it++) {
//     //     cout << "it : " << *it << '\n';
//     // }

//     while (q--) {
//         string s = "";
//         for (int i = 0;i < pow(2, k);i++) {
//             char x; cin >> x;
//             s += x;
//         }
//         if (ans.find(s) == ans.end()) cout << "no" << '\n';
//         else cout << "yes" << '\n';
//     }
// }