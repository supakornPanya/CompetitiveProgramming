#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    int pairSum(ListNode* head) {
        int size = 0, maxx = 0;
        vector<int> val;
        //mark value of each node by vector<int> val
        while (head != nullptr) {
            val.push_back(head->val);
            head = head->next; size++;
        }
        //loop each twin to find maxx
        for (int i = 0;i < size / 2;i++) {
            maxx = max(maxx, val[i] + val[size - 1 - i]);
        }
        return maxx;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}