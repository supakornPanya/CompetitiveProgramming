#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) { return head->next; }
        ListNode* preMid = head;
        ListNode* tail = head;
        tail = tail->next->next;
        //loop each set(0, (1,2), (3,4), ...)
        //each set have same middle node
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next->next;
            preMid = preMid->next;
        }
        //preMid->next = next of middle node
        preMid->next = preMid->next->next; 
        return head;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}