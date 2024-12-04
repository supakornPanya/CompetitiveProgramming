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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool add = false;
        int val1, val2;
        ListNode* end = new ListNode();
        ListNode* head = new ListNode();
        ListNode* ans = head;
        while (l1->next != end || l2->next != end || add) {
            //find value of node
            if (l1->next == end) { val1 = 0; } else { val1 = l1->val; }
            if (l2->next == end) { val2 = 0; } else { val2 = l2->val; }
            //pointing new node
            if (l1->next == nullptr || l1->next == end) { l1->next = end; } else { l1 = l1->next; }
            //*|-> 1st find ->next==NULL will can get value in node then get value again will will ->next is end
            //*    that will get value 0
            if (l2->next == nullptr || l2->next == end) { l2->next = end; } else { l2 = l2->next; }
            //find value of new node ans
            int sum = val1 + val2 + add;
            int temp = (sum) % 10;
            add = (sum >= 10) ? true : false;
            cout << val1 << ", " << val2 << ", " << temp << endl;
            //connect ans node
            ListNode* newNode = new ListNode(temp);
            ans->next = newNode;
            ans = ans->next;
        }
        return head->next;
    }
};

int main() {
    //Solution sol;
    //???? How to create test case of linked list
}