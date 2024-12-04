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

//bfs each node and add last node in queue of each level
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) { return {}; }
        queue<TreeNode*> q; q.push(root);
        int n;
        vector<int> ans;
        while (!q.empty()) {
            //loop each level
            n = q.size();
            for (int i = 0;i < n;i++) {
                TreeNode* node = q.front(); q.pop();
                cout << node->val << ", ";
                if (i == n - 1) { ans.push_back(node->val); }
                if (node->left != nullptr) { q.push(node->left); }
                if (node->right != nullptr) { q.push(node->right); }
            }
            cout << endl;
        }
        return ans;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}