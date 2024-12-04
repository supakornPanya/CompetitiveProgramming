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

//using 2 pointer both pointer always far n node 
//|->1st pointer(BeDeNode) try to point to before delete node
//|->2nd pointer(end) try to point to end of list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* BeDeNode = dummyHead;
        ListNode* end = dummyHead;
        for (int i = 0;i < n;i++) { //-->move end pointer far from BeDeNode n node
            //cout << end->val << ", "; 
            end = end->next; 
        }
        cout << endl << "-----------" << endl;
        while (end->next != nullptr) { //-->move end and BeDeNode to end node is end of list
            //cout << "Before : " << BeDeNode->val << ", " << end->val << endl;
            BeDeNode = BeDeNode->next;
            end = end->next;
            //cout << "After : " << BeDeNode->val << ", " << end->val << endl;
        }
        //cout << "end : " << BeDeNode->val << ", " << end->val << endl;

        //-->before deleted Node points to next of deleted Node -> deallocate Deleted Node
        ListNode* DeNode = BeDeNode->next;
        BeDeNode->next = DeNode->next;
        delete DeNode;
        
        return dummyHead->next;
    }
};

int main() {
    Solution sol;
    //run in leet code
}