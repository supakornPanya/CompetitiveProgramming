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
    bool ans = true;

    void dfs(TreeNode* now, long long l, long long u) {
        if (now == nullptr) { return; }
        int NowVal = now->val;
        if (l >= NowVal || NowVal >= u) { ans = false; return; }
        dfs(now->left, l, NowVal);
        dfs(now->right, NowVal, u);
    }

    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) return true;
        long long l = 1e11 * -1;//lower bound=bigest value parent that give lower bound
        long long u = 1e11;//upper bound=least value parent that give upper bound
        dfs(root, l, u);
        return ans;
    }
};
//algorithm for solve problem : 
// |->all node from left child node and left child node must less than parent node
// |->all node from right child node and right child node must greater than parent node
//brute force solution :
// |->check all parent/ancestor node :
//     |->node who creates right child node will give lower bound for child 
//     |->node who creates left child node will give upper bound for child
//algorithm solution : 
// |->best lower/upper bound is last parent/ancestor who give that bound 
//    |example->node(ancestor) has right child(parent) node then child node has right child node 
//              that has 2 lower bound so parent node will greater than ancestor.
//              when compare all node lower bound will get biggest value = parent node

//solution : https://leetcode.com/problems/validate-binary-search-tree/solutions/5337557/solution/

int main(){
    Solution sol;
    //run in leet code
}