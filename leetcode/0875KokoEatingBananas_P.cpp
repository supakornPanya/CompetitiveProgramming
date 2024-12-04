#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //l,r = range for search(speed eating per hour)
        //mid_k = mid from l,r (speed eating pre hour), ans = minimum value speed eating that give hNew <= h
        int l = 1, r = 1, mid_k, ans = INT_MAX; 
        long long hNew; //hNew = a hour eating from using eating mid_k(speed eating per hour)
        for (int p : piles) { r = max(p, r); } //find the max value of k that can use

        cout << "r : " << r << endl;

        while (l <= r) {

            mid_k = (l + r) / 2, hNew = 0;
            for (int i = 0;i < piles.size();i++) {
                hNew += piles[i] / mid_k;
                if (piles[i] % mid_k != 0 || piles[i] < mid_k) { hNew++; } //case have remainder/floor divide
            }

            cout << "mid_k : " << mid_k << ", hNew : " << hNew << ", l : " << l << ", r : " << r;

            //find max hNew that hNew <= h(max value can use for hNew)
            //hNew <= h(max) -> increasing hNew -> by decreasing(hNew+=piles[i]/mid_k;) mid_k(mid_k = (l+r)/2)
            //hNew <= h(max) -> can use this hNew -> using min() because we want min k that she can eat all the bananas within h hours.
            if (hNew <= h) { 
                cout << ", case 1 " << endl;
                ans = min(mid_k, ans);
                r = mid_k - 1;
            }
            //find max hNew that hNew <= h(max value can use for hNew)
            //hNew > h(max) -> decreasing hNew -> by increasing(hNew+=piles[i]/mid_k;) mid_k(mid_k = (l+r)/2) 
            if (hNew > h) {
                cout << ", case 2 " << endl;
                l = mid_k + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = { 3,6,7,11 };
    int h = 8;
    int ans = sol.minEatingSpeed(piles, h);

    cout << "ans : " << ans;
}