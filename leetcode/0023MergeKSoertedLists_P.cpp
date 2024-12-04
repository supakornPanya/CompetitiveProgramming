#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//O(NlogN) = for each element push to priority_queue then create list answer sorted by priority_queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        //O(NlogN) : loop N element in lists * push in pq each element
        for (int i = 0;i < lists.size();i++) {
            ListNode* list = lists[i];
            while (list != nullptr) {
                int val = list->val;
                pq.push(val);
                list = list->next;
                cout << val << ", ";
            }
            cout << endl;
        }
        ListNode* head = new ListNode();
        ListNode* list = head;
        //O(NlogN) : loop N element * pop in pq
        while (!pq.empty()) {
            int val = pq.top(); pq.pop();
            ListNode* node = new ListNode(val);
            list->next = node;
            list = list->next;
        }
        return head->next;
    }
};

int main() {
    //I am lazy to create test case linked list so run this code in leet code
}