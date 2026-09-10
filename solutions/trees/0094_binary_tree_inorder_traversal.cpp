class Solution {
public:
    vector<int> result;

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;

        inorder(node->left);

        result.push_back(node->val);

        inorder(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};