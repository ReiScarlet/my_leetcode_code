#include <cstddef>
#include <queue>

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        std::queue<Node *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node *cur = q.front();
                q.pop();
                if (size != 0) {
                    cur->next = q.front();
                } else {
                    cur->next = nullptr;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};