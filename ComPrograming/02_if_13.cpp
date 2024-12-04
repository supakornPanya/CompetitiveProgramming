#include <bits/stdc++.h>
using namespace std;

int main() {
    double minn = DBL_MAX, maxx = DBL_MIN, sum = 0; 
    for(int i = 0;i < 4;i++){
        double x; cin >> x;
        sum += x;
        if(x > maxx) { maxx = x; }
        if(x < minn) { minn = x; }
    }
    //cout << sum << " " << minn << " " << maxx << endl;
    cout << round(((sum - minn - maxx) / 2) * 100.0) / 100.0;
}