#include <bits/stdc++.h>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode();
        ListNode* after = new ListNode();
        ListNode* headBefore = before;
        ListNode* headAfter = after;
        ListNode* list = head;
        while (list != nullptr) {
            int val = list->val;
            if (val < x) {
                before->next = list;
                before = before->next;
            } else {
                after->next = list;
                after = after->next;
            }
            list = list->next;
        }
        after->next = nullptr;
        before->next = headAfter->next;
        return headBefore->next;
    }
};

int main(){
    Solution sol;
    //I lazy to create link list so run this code in leet code
}