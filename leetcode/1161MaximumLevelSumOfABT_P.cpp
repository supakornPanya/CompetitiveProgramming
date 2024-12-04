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

//bfs and sum of level
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        int n, maxx = INT_MIN, level = 0, ans;
        while (!q.empty()) {
            int sum = 0;
            level++;
            n = q.size();
            for (int i = 0;i < n;i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->right != nullptr) { q.push(node->right); }
                if (node->left != nullptr) { q.push(node->left); }
            }
            cout << sum << endl;
            if (sum > maxx) {
                maxx = sum;
                ans = level;
            }
        }
        return ans;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}