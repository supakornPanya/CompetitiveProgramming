#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long d = 2;
    
    if(n < 2) {
        cout << "No prime factors for numbers less than 2." << endl;
        return 0;
    }

    while(n > 1) {
        if(d * d > n) {
            cout << n << " "; 
            return 0;
        }
        while(n % d == 0) {
            n /= d;
            cout << d << " ";
        }
        d += 1;
    }

    return 0;   
}