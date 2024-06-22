#include <unordered_map>
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
    std::unordered_map<int, int> m_index;

private:
    TreeNode *buildTreeImpl(std::vector<int> &preorder,
                            std::vector<int> &inorder, int preorder_left,
                            int preorder_right, int inorder_left,
                            int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int preorder_root = preorder_left;
        int inorder_root = m_index[preorder[preorder_root]];
        TreeNode *root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = buildTreeImpl(preorder, inorder, preorder_left + 1,
                                   preorder_left + size_left_subtree,
                                   inorder_left, inorder_root - 1);
        root->right = buildTreeImpl(
            preorder, inorder, preorder_left + size_left_subtree + 1,
            preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        const int n = preorder.size();
        for (int i = 0; i < n; i++) {
            m_index[inorder[i]] = i;
        }
        return buildTreeImpl(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};