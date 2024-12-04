#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/* Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//!sol 1 :
// fastest may be, bfs each layer -> connect each node
// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q; q.push(root);
//         while (!q.empty()) {
//             int sizeLayer = q.size();
//             Node* beforeNode = q.front(); q.pop();
//             if (beforeNode != nullptr) {
//                 q.push(beforeNode->left); q.push(beforeNode->right);
//             }
//             cout << "sizeLayer : " << sizeLayer << endl;
//             for (int i = 0;i < sizeLayer - 1;i++) {
//                 //cout << "i : " << i << ", ";
//                 Node* node = q.front(); q.pop();
//                 if (node == nullptr) { continue; }
//                 //cout << "node->val : " << node->val;
//                 beforeNode->next = node;
//                 //cout << ", beforeNode->val : " << beforeNode->val << endl;
//                 beforeNode = node;
//                 q.push(node->left); q.push(node->right);
//             }
//             //cout << endl;
//         }
//         return root;
//     }
// };

//!sol 2 :
//almost fastest, dfs and connect child node  
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) { return root; }
        root->left->next = root->right;
        root->right->next = (root->next != nullptr) ? root->next->left : nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main() {
    //I am lazy to create link list.so run this class in leetCode
}