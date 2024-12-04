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
//sol : using l,r for connect list.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(99);
        ans->next = head;
        ListNode* l = ans; //left node
        ListNode* r = head; //right node
        while (r != nullptr) {
            //r this and next is duplicate so find r isn't duplicate element
            //then connect l with r that next of duplicate element
            if (r->next != nullptr && r->val == r->next->val) {
                cout << "case1 : " << l->val << ", " << r->val << endl;
                while (r->next != nullptr && r->val == r->next->val) {
                    r = r->next;
                }
                r = r->next; 
                l->next = r;
            } 
            //element isn't duplicate so pointer next element
            else {
                cout << "case2 : " << l->val << ", " << r->val << endl;
                r = r->next;
                l = l->next;
            }
        }
        return ans->next;
    }
};

int main() {
    //I lazy to create link list so run this code in leet code
}