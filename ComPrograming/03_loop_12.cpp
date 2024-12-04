#include <bits/stdc++.h>
using namespace std;

int main() {
    double long n; cin >> n;
    //binary search
    double long l = 0, r = ceil(n / 10); //range of power(a, ?)
    while(true){
        double long mid = (l + r) / 2;
        if(abs(n - pow(10, mid)) <= pow(10, -10) * max(n, pow(10, mid))) {
            cout << mid;
            break;
        } 
        else if (pow(10, mid) < n) {
            l = mid + 1;
        }
        else if (pow(10, mid) > n) {
            r = mid - 1;
        }
    } 
}