#include <bits/stdc++.h>
using namespace std;

//O(NlogN + N), NlogN is sort, N is loop each element
//loop each element if(newStart < oldEnd):2 intervals is overlap
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int ansStart = intervals[0][0], ansEnd = intervals[0][1];

        for (int i = 1;i < intervals.size();i++) {
            int start2 = intervals[i][0], end2 = intervals[i][1];
            //cout << ansStart << ", " << ansEnd << ", " << start2 << ", " << end2 << "; ";
            
            if (start2 <= ansEnd) {//-->intervals is overlap
                //cout << "sol1";
                ansEnd = (ansEnd > end2) ? ansEnd : end2; //-->merge intervals
            } 
            else if(start2 > ansEnd){//-->intervals isn't overlap
                //cout << "sol2";
                ans.push_back({ ansStart, ansEnd }); //-->push pervious intervals
                //-->set new compare interval
                ansStart = start2;
                ansEnd = end2;
            }
            
            //cout << endl;
        }
        ans.push_back({ ansStart, ansEnd });
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = { {1,3} ,{2,6},{8,10},{15,18},{17,23} };
    vector<vector<int>> ans = sol.merge(intervals);

    cout << "ans------" << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}