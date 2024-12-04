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

//two pointer for each linked list
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* ans = dummyHead;
        while (list1 != nullptr && list2 != nullptr) {
            int val1 = list1->val, val2 = list2->val;
            if (val1 < val2) { //list1 is less than list2 the add list1 to list ans
                //cout << "val1 : " << val1 << endl;
                ans->next = new ListNode(val1);
                list1 = list1->next;
                ans = ans->next;
            } else { //list2 is less than list1 then add list2 to list ans
                //cout << "val2 : " << val2 << endl;
                ans->next = new ListNode(val2);
                list2 = list2->next;
                ans = ans->next;
            }
        }
        //some list(lits1 or list2) have left some node that isn't add to ans list
        if (list1 != nullptr) {
            //cout << "a1" << endl;
            ans->next = list1;
        }
        if (list2 != nullptr) {
            //cout << "a2" << endl;
            ans->next = list2;
        }
        return dummyHead->next;
    }
};


int main(){
    Solution sol;
    //run on leet code
}