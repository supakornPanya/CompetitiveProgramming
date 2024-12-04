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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //trap case-->
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        int count = 0;
        ListNode* end = head;

        //O(n) : find how many node in list -->
        cout << "all node : ";
        while (end->next != nullptr) {
            cout << end->val << ", ";
            end = end->next;
            count++;
        }cout << end->val << ", " << endl;

        //calculate node cut -->
        cout << "count : " << count + 1 << endl;
        int cut = (count + 1) - (k % (count + 1)) - 1;
        cout << "cut : " << cut << endl;
        ListNode* cutNode = head;
        
        //rotate all node == same position
        if (cut == count) { return head; }

        //find cut node -->
        cout << "cut node : ";
        for (int i = 0;i < cut;i++) {
            cout << cutNode->val << ", ";
            cutNode = cutNode->next;
        }cout << cutNode->val << ", " << endl;

        //cut & connect node
        ListNode* ans = cutNode->next; 
        cutNode->next = nullptr;
        end->next = head;

        return ans;
    }
};


int main(){
    //I am lazy so run this code in leet code
}