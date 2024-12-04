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

class Solution {
public:
    int count = 0; //count = path that sum equal targetSum
    void dfs(TreeNode* node, int targetSum, long long curSum, unordered_map<long long, int>& m) {
        //node = this node
        //targetSum = target sum of path
        //currSum = sum from root path to node
        //m = map all path that start root end in some node from root to node
        if (node == nullptr) {
            return;
        }

        curSum += node->val;
        if (curSum == targetSum) { count++; } //this path is equal to targetSum
        // somePath = curSum - targetSum
        // targetSum = curSum - somePath
        //curSum = root to now node
        //somePath = root to x node(x node = some node from root to node that in path root to before now node)
        //curSum - somePath = next of x node to now node
        count += m[curSum - targetSum]; 

        m[curSum]++; //mark this path
        dfs(node->left, targetSum, curSum, m);
        dfs(node->right, targetSum, curSum, m);
        m[curSum]--; //cancel mark this path 
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        dfs(root, targetSum, 0, m);
        return count;
    }
};

int main() {
    //I lazy to create tree so run this class in leet code
}