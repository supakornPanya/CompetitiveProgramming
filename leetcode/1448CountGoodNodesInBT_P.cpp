#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//!sol
//->maxVal is max of parent path because we use maxVal from pass in fuction
class Solution {
public:
    int count = 0;
    void sol(TreeNode* root, int maxVal) {
        if (root == nullptr) { return; }
        cout << "val : " << root->val << ", maxVal : " << maxVal << ", ";
        if (root->val >= maxVal) {
            cout << "true";
            maxVal = root->val;
            count++;
        }
        cout << endl;
        sol(root->left, maxVal);
        sol(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        sol(root, root->val);
        return count;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}