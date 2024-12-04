#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    int i = 1;
    vector<int> ans;
    while(i <= n) {
        //cout << i << endl;
        i++;
        if(n % i == 0) {
            n = n / i; 
            ans.push_back(i);
            i = 1;
        }
    }

    for(int i = 0;i < ans.size();i++){
        cout << ans[i];
        if(i != ans.size() - 1) { cout << "*"; }
    }

    return 0;
}