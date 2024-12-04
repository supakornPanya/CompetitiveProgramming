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


//!sol 1 dfs
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == nullptr) { return nullptr; } //case this node is nullptr
//         if (root->val == val) { return root; } //case this node is equal to val

//         TreeNode* left = searchBST(root->left, val); //call left node
//         TreeNode* right = searchBST(root->right, val); //call right node

//         if (left != nullptr) return left; //left child node have node answer
//         else if (right != nullptr) return right; //right child node have node answer
//         else return nullptr; //left and right child node doesn't answer child node
//     }
// };

//!sol 2 bfs fastest
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q; q.push(root);

        while (!q.empty()) {
            int n = q.size();
            //loop each level of tree
            for (int i = 0;i < n;i++) {
                TreeNode* node = q.front(); q.pop();
                if (node == nullptr) continue; //case this node nullptr
                if(node->val == val) return node; //case this node is answer

                q.push(node->left); //push left child node in queue
                q.push(node->right); //push right child node in queue    
            }
        }

        return nullptr;
    }
};


int main() {
    //I lazy to create tree so run this class in leet code
}