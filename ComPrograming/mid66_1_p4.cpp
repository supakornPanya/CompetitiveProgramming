#include <bits/stdc++.h>
using namespace std;

string f(char a, int n) {
    string s = ""; for (int i = 0;i < n;i++) { s += a; }
    return s;
}

int main() {

    int q; cin >> q; cin.ignore();
    while (q--) {

        char a1, a2; int n1, n2; cin >> a1 >> n1 >> a2 >> n2;
        unsigned long long n = stoull(f(a1, n1) + f(a2, n2));

        if (n % 2 == 0) { cout << "NO" << endl; continue; }
        bool flag = false;
        for (unsigned long long i = 3;i <= sqrt(n);i += 2) {
            if (n % i == 0) { 
                cout << "NO" << endl; 
                flag = true; 
                continue; 
            }
        }
        if (!flag) cout << "YES" << endl;

    }

    return 0;
}


//!this sol allocate vector overflow
// #include <bits/stdc++.h>
// using namespace std;

// string f(char a, int n) {
//     string s = ""; for (int i = 0;i < n;i++) { s += a; }
//     return s;
// }

// int main() {
//     vector<long long> qq;
//     long long maxx = -1;

//     int q; cin >> q; cin.ignore();
//     while (q--) {
//         char a1, a2; int n1, n2; cin >> a1 >> n1 >> a2 >> n2;
//         long long n = stoll(f(a1, n1) + f(a2, n2));
//         qq.push_back(n); 
//         maxx = (n > maxx)? n : maxx;
//     }

//     //find prime to maxx
//     long long n = maxx;
//     cout << "maxx : " << n << endl;
//     return 0;
//     vector<bool> flag(n + 10, false);
//     for (int i = 2;i <= n;i+=2) {
//         flag[i] = true;
//     }
//     for (int i = 3;i <= n / 2;i++) {
//         if(!flag[i]) {
//             for(int j = i * i;j <= maxx;j += i) {
//                 flag[j] = true;
//             }
//         }
//     }

//     //loop question
//     for(long long x : qq) {
//         if(flag[x] == false) { cout << "YES" << endl; }
//         else { cout << "NO" << endl; }
//     }

//     return 0;
// }