#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx = (gain[0] > 0) ? gain[0] : 0;
        for(int i = 1;i < gain.size();i++){
            gain[i] = gain[i] + gain[i - 1];
            maxx = max(gain[i], maxx);
        }
        return maxx;
    }
};

int main() {
    Solution sol;
    vector<int> gain = {-5,1,5,0,-7};
    int ans = sol.largestAltitude(gain);

    cout<<"ans : "<<ans;
}