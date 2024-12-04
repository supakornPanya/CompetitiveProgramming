#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int sizeLayer = q.size();
            for (int i = 0;i < sizeLayer;i++) {
                TreeNode* Node = q.front(); q.pop();
                if (Node->left != nullptr) { q.push(Node->left); }
                if (Node->right != nullptr) { q.push(Node->right); }
                temp.push_back(Node->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    //run in leet code
}