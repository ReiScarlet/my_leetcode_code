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
    TreeNode *buildTreeImpl(std::vector<int> &inorder,
                            std::vector<int> &postorder, int inorder_left,
                            int inorder_right, int postorder_left,
                            int postorder_right) {
        if (inorder_left > inorder_right)
            return nullptr;
        int postorder_root = postorder_right;
        int root_val = postorder[postorder_root];
        int inorder_root = m_index[root_val];
        TreeNode *root = new TreeNode(root_val);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = buildTreeImpl(inorder, postorder, inorder_left,
                                   inorder_root - 1, postorder_left,
                                   postorder_left + size_left_subtree - 1);
        root->right = buildTreeImpl(
            inorder, postorder, inorder_root + 1, inorder_right,
            postorder_left + size_left_subtree, postorder_right - 1);
        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &inorder,
                        std::vector<int> &postorder) {
        const int n = inorder.size();
        for (int i = 0; i < n; i++) {
            m_index[inorder[i]] = i;
        }
        return buildTreeImpl(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};