#include <bits/stdc++.h>
using namespace std;

//!sol1 little mem but middle runtime
//T : O(N)
//S : O(N)
//sol : loop element to compare with newInterval to (Null, merge, put to ans)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) { return { newInterval }; }
        int startNew = newInterval[0], endNew = newInterval[1];
        vector<vector<int>> ans;
        for (int i = 0;i < intervals.size();i++) {
            int start = intervals[i][0], end = intervals[i][1];

            cout << start << ", " << end << ", " << startNew << ", " << endNew << ", " << endl;

            if (startNew <= start && end <= endNew) { //old in new
                cout << "case1" << endl; //startNew--start--end--endNew
            } else if (start <= startNew && endNew <= end) { //new in old
                cout << "case2" << endl; //start--startNew--endNew--end
                startNew = start;
                endNew = end;
            } else if (start <= startNew && startNew <= end) {//overlap
                cout << "case3" << endl; //start--StartNew--end--endNew
                startNew = start;
            } else if (start <= endNew && endNew <= end) {//overlap
                cout << "case4" << endl; //startNew--start--endNew--end
                endNew = end;
            } else { //not overlap
                if(endNew < start){
                    cout << "case5.1" << endl; //startNew--endNew--start--end
                    ans.push_back({ startNew, endNew });
                    startNew = start;
                    endNew = end;
                } else { 
                    cout << "case5.2" << endl; //start--end--startNew--endNew
                    ans.push_back({ start, end });
                }
            }

            cout << "ans : ";
            for (int i = 0;i < ans.size();i++) {
                cout << ans[i][0] << ":" << ans[i][1] << ", ";
            }cout << endl;
            cout << "---------------------------------" << endl;

        }
        if (ans.size() == 0 || ans[ans.size() - 1][1] < startNew) {
            cout << "case ending" << endl;//last element is merge so put last merge interval
            ans.push_back({ startNew, endNew });
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
//         return ans;
//     }
// };

int main() {
    Solution sol;

    //vector<vector<int>> intervals = { {1,5} };
    //vector<int> newInterval = { 2, 3 };
    vector<vector<int>> intervals = { {2,5} ,{6,7},{8,9} };
    vector<int> newInterval = { 0, 1 };
    //vector<vector<int>> intervals = { {1,2} ,{3,5},{6,7},{8,10},{12,16} };
    //vector<int> newInterval = { 4, 8 };

    vector<vector<int>> ans = sol.insert(intervals, newInterval);

    cout << "ansEnding : " << endl;
    for (auto xx : ans) {
        for (auto x : xx) {
            cout << x << ", ";
        }cout << endl;
    }
}