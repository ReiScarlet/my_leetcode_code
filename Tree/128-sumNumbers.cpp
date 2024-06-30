#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0;

private:
    void traceback(TreeNode *root, int sum) {
        sum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            res += sum;
            return;
        }
        if (root->left) {
            traceback(root->left, sum);
        }
        if (root->right) {
            traceback(root->right, sum);
        }
    }

public:
    int sumNumbers(TreeNode *root) {
        traceback(root, 0);
        return res;
    }
};