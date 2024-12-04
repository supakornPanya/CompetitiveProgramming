#include <bits/stdc++.h>
using namespace std;

//! brute force 0 to n
//0-9 : 1*10
//0-99 : 2*90 + 10 = 180 + 10 = 190
//0-999 : 3*900 + 2*90 + 10 = 2700 + 180 + 10 = 2890 
//0-123 : 3*x + 2*90 + 10 = 72 + 180 + 10 = 262
//! brute force n to m
// int main() {
//     int n, m; cin >> n >> m;
//     int cnt = 0, c = 0; 
//     for (int i = n;i <= m;i++){
//         cout << to_string(i).size() << " ";
//         if (to_string(i).size() == 3) c++;
//         cnt += to_string(i).size();
//     }
//     cout << cnt << " " << c;
// }
//! normal solution to find 0 to n
// int main() {
//     int main() {
//         int n, m; cin >> n >> m;
//         int sum1 = 0, sum2 = 0;

//         int i = 1, x = 1;
//         while (x * 10 <= n) { //in case x > 99 || x > 999 || x > 99999 || .... 
//             sum1 += (9 * x) * i;
//             //cout << "90 * i : " << (9 * x) * i << ", sum1 : " << sum1 << endl;
//             i++; x *= 10;
//         }
//         n -= x;
//         //cout << "sum1 : " << sum1 << ", (n * i) : " << (n * i) + i + 1 << endl;
//         sum1 = sum1 + (n * i) + i + 1; 

//         cout << sum1;
//     }
// }

int main() {
    long long n, m; cin >> n >> m;
    long long sum1 = 0, sum2 = 0;

    //find 0 to m
    long long i = 1, x = 1;
    while (x * 10 <= m) {
        sum2 += (9 * x) * i;
        i++; x *= 10;
        cout << "sum2 : " << sum2 << endl;
    }
    m -= x;
    cout << "m : " << m << endl;
    // sum += ((m - x + 1) * i) + 1
    // (m - x) length that each digit is long i
    sum2 += (m * i) + i + 1; 

    //find 0 to n-1
    i = 1, x = 1; n--;
    while (x * 10 <= n) {
        sum1 += (9 * x) * i;
        i++; x *= 10;
    }
    n -= x;
    sum1 += ((n) * i) + i + 1;

    cout << sum2 - sum1;
}
