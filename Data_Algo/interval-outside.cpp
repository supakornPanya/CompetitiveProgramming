//-----------------------using own lower_bound & upper_bound
#include <bits/stdc++.h>
using namespace std;

// int searchh(vector<int>& v, int x) {
//     int l = 0, r = v.size() - 1, mid;
//     while(l <= r) {
//         mid = (l + r) / 2;
//         if(v[mid] == x){
//             return mid;
//         } else if(v[mid] > x) {
//             r = mid - 1;
//         } else if(v[mid] < x) {
//             l = mid + 1;
//         }
//     }
//     return mid;
// }

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int x; cin >> x; v.push_back(x);
    }
    
    // for(int i = 0;i < v.size();i++) {
    //     cout << v[i] << " ";
    // } cout << endl;

    sort(v.begin(), v.end());
    for (int i = 0;i < m;i++) {
        int x; cin >> x;
        auto r = upper_bound(v.begin(), v.end(), x + k);
        auto l = lower_bound(v.begin(), v.end(), x - k);
        // cout << "l : " << *l << ":" << r - v.begin() << ", r : " << *r << ":" << r - v.begin() << " ";
        cout << (r - v.begin()) - (l - v.begin()) << " ";
    }

    return 0;
}

//---------------------------lower bound & upper bound 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, m, k; cin >> n >> m >> k;
//     vector<int> v;
//     for (int i = 0;i < n;i++) {
//         int x; cin >> x; v.push_back(x);
//     }

//     sort(v.begin(), v.end());
//     for (int i = 0;i < m;i++) {
//         int x; cin >> x;
//         auto r = upper_bound(v.begin(), v.end(), x + k);
//         auto l = lower_bound(v.begin(), v.end(), x - k);
//         cout << (r - v.begin()) - (l - v.begin()) << " ";
//     }

//     return 0;
// }