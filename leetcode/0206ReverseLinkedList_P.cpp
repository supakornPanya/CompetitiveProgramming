#include <bits/stdc++.h>
using namespace std;

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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            if (node != nullptr) cout << node->val << " " << head->val << endl;
            else cout << " -- " << endl;
            head->next = node;
            node = head;
            head = next;
        }
        return node;
    }
};

int main() {
    //I lazy to create linked list so run this class in leet code
}