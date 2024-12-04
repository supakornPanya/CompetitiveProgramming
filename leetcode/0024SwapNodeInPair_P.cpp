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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* beforeNode = dummyHead;
        while(beforeNode->next->next != nullptr){
            if (beforeNode->next->next == nullptr) { break; }
            //swap 2 node adjacent = swap(nowNode, nextNode);
            ListNode* nowNode = beforeNode->next;
            ListNode* nextNode = beforeNode->next->next;
            beforeNode->next =  nextNode;
            nowNode->next = nextNode->next;
            nextNode->next = nowNode;
            
            beforeNode = nowNode;
        }
        return dummyHead->next;
    }
};

int main() {
    //I am lazy so run in leetCode
}