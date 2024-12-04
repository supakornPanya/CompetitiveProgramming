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
/*
 Definition for a Node.
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

//fastest O(N), bfs, loop each layer -> connect each node
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q; q.push(root);
        while (!q.empty()) {
            int sizeLayer = q.size();

            //*set first node in level
            Node* beforeNode = q.front(); q.pop();
            if (beforeNode != nullptr) {
                //cout << "before : " << beforeNode->val;
                q.push(beforeNode->left); q.push(beforeNode->right);
            }

            //*loop level
            for (int i = 0;i < sizeLayer - 1;i++) {
                Node* node = q.front(); q.pop();
                //cout << ", x:";

                //*protect NULL node calls node->left, node->right    
                if (node == nullptr) { continue; }
                
                q.push(node->left); q.push(node->right);

                //*protect beforeNode calls beforeNode->next and set new value beforeNode
                if (beforeNode == nullptr) { beforeNode = node; continue; }
                
                //cout << node->val << ", ";
                beforeNode->next = node;
                beforeNode = node;
            }
            //cout << endl;
        }
        return root;
    }
};

int main() {
    //I am lazy to create link list.so run this class in leetCode
}