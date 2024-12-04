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

//3 case of LCM
//1)upper node of LCM : 1 node(left or right) is LCM node and another node is nullptr 
//  so we return node that isn't nullptr == return LCM node
//2)this node is LCM : return this node
//3)lower node of LCM : 1 node(left or right) is p or q node and another node is nullptr
//  so we return node of node is p or q.
//  we will return node isn't null until we found another node p or q this will in case this node is LCM

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //**base case-->
        //this node is nullptr == end of node
        if (root == nullptr) { return nullptr; }
        //found p or q -> it isn't necessary for search next 
        //because if another p or q is child node of this node another node that will search will return null
        //then a node can return to root node is this node 
        if (root == p || root == q) { return root; }

        //call left and right child node 
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        //**case-->
        //1)this node is LCM : 
        //back track or child of left and right child node is p and q
        if ((l == p && r == q) || (l == q && r == p)) {
            return root;
        }
        //2.1)have found 1 node p or q from right node
        else if ((l != nullptr) && r == nullptr) {
            return l;
        }
        //2.2)have found 1 node p or q from right node 
        else if (l == nullptr && (r != nullptr)) {
            return r;
        }
        //3) still not fond p and q node
        return nullptr;
    }
};

int main() {
    //I lazy to crate linked list so run this class in leet code
}