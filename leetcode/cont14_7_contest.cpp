#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string getSmallestString(string s) {
//         for (int i = 0;i < s.size() - 1;i++) {
//             if ((s[i] % 2 == 0 && s[i + 1] % 2 == 0)
//                 || (s[i] % 2 == 1 && s[i + 1] % 2 == 1)) {
//                 if (s[i] > s[i + 1]) {
//                     swap(s[i], s[i + 1]);
//                     return s;
//                 }
//             }
//         }
//         return s;
//     }
// };


//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         set<int> s;
//         for (int x : nums) { s.insert(x); }

//         ListNode* preNode = new ListNode();
//         preNode->next = head;

//         ListNode* node = head;

//         ListNode* ans = new ListNode();
//         ans->next = preNode;

//         while (node != nullptr) {
//             if (s.find(node->val) != s.end()) {
//                 cout << node->val << ", ";
//                 preNode->next = node->next;
//                 node = node->next;
//             } else {
//                 preNode = preNode->next;
//                 node = node->next;
//             }
//         }
//         return ans->next->next;
//     }
// };





class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<pair<int,int>> pq; //value, row or column
        for(int x:horizontalCut){ //horizontal is 0
            pq.push({x, 0});
        }
        for(int x:verticalCut){ //vertical is 1
            pq.push({x, 1});
        }

        int row = 1, col = 1, sum = 0; 
        while(!pq.empty()){
            pair<int,int> node = pq.top(); pq.pop();
            if(node.second == 0){
                sum += node.first * col;
                row++;
            } else { //node.second is 1
                sum += node.first * row;
                col++;
            }
        }
        return sum;
    }
};



int main() {
    Solution sol;
    int m = 3, n = 2;
    vector<int> h = {1,3};
    vector<int> v = {5};
    int ans = sol.minimumCost(m, n, h, v);
    
    cout << "ans : " << ans;
}