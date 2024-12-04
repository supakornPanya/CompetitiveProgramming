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
    int maxx = 0;
    void sol(TreeNode* root, int count, bool left){
        if(root == nullptr) { 
            maxx = max(maxx, count);
        }

        //this node is left child node
        if(left){ 
            sol(root->left, 0, true); //left -> left new count of zigzag
            sol(root->right, count + 1, false); //left -> right continue count of zigzag
        }
        //this node is right child node  
        else { 
            sol(root->left, count + 1, true); //right -> left continue count of zigzag
            sol(root->right, 0, false); //right -> right new count of zigzag
        }
    }

    int longestZigZag(TreeNode* root) {
        sol(root->left, 0, true);
        sol(root->right, 0, false);

        return maxx;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}