#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        travel(root);
        swap(ans1->val, ans2->val);
    }
protected:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    TreeNode* ans1;
    TreeNode* ans2;
    void travel(TreeNode* root) {
        if(root == NULL) return;

        pq2.push(root->val);
        travel(root->left);
        pq2.pop();

        pq1.push(root->val);
        travel(root->right);
        pq1.pop();
    }
};

int main() {
    ///--------------
}