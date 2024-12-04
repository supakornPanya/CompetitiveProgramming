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
//! O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* list = new ListNode();
        ListNode* ans = list;
        int BeVal = -1000; //value before node
        while(head != nullptr){
            if(BeVal != head->val){
                list->next = head;
                list = list->next;
            }
            head->next;
        }
        list->next = nullptr;
        return ans->next;
    }
};

int main() {
    //I lazy to create link list so run this code in leet code
}