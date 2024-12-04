#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* headOdd = head;
        ListNode* tailOdd = head;
        ListNode* headEven = head->next;
        ListNode* tailEven = head->next;
        head = head->next->next;
        int count = 3;
        while(head != nullptr){
            if(count % 2 == 0) { 
                tailEven->next = head;
                tailEven = tailEven->next;
            }else {
                tailOdd->next = head;
                tailOdd = tailOdd->next;
            }
            head = head->next;
            count++;
        }
        tailEven->next = nullptr;
        tailOdd->next = headEven;
        return headOdd;
    }
};

int main() {
    //I lazy to create linked list so run this class in leet code
}