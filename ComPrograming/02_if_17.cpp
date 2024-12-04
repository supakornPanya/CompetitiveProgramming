#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    if(x > 2000) { cout << "Reject"; }
    else if(x > 1000) { cout << "58"; }
    else if(x > 500) { cout << "38"; }
    else if(x > 250) { cout << "28"; }
    else if(x > 100) { cout << "22"; }
    else { cout << "18"; }
}