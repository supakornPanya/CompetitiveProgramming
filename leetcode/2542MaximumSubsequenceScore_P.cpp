#include <bits/stdc++.h>
using namespace std;

//!sol : 
//1)page nums1 and nums2 and then sort by nums2
//2)loop from largest to smallest of nums2
//  when index i value of nums2[i]. largest value of sum is chose k element form index largest to index i.
//  case 1 : used greater than k -> pop smallest of element nums1 from combination because in this index i min value of nums2 still constant so you can greedy chose max value k element from nums1 
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        //page pair of each index + sort
        vector<pair<int, int>> v;
        for (int i = 0;i < nums1.size();i++) {
            v.push_back({ nums2[i], nums1[i] });
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        cout << "v : " << endl;
        for (auto x : v) {
            cout << x.first << ", " << x.second << endl;
        }cout << "--------------" << endl;

        priority_queue<int, vector<int>, greater<int>> pq; //for keep min element that used in sum

        long long sum = 0, used = 0, maxx = v[0].first * v[0].second;
        for (int i = 0;i < v.size();i++) {
            pair<int, int> node = v[i]; 
            pq.push(node.second); //push nums1 to pq
            sum += node.second; //add nums1 to sum
            used++; 

            cout << "node : " << node.first << ", " << node.second << endl;
            cout << "sum * node.first : " << sum * node.first << ", maxx : " << maxx << endl;
            cout << "used : " << used << endl;

            if (used == k) { //correct k element

                cout<<"used == k "<<endl;
            
                maxx = max(sum * node.first, maxx); //this sum is grater than old sum?
                sum -= pq.top(); //pop smallest element in sum
                pq.pop(); //pop smallest element in sum
                used--;
            }
        }
        return maxx;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { 1,3,3,2 };
    vector<int> nums2 = { 2,1,3,4 };
    int k = 3;
    long long ans = sol.maxScore(nums1, nums2, k);

    cout << "ans : " << ans;
}