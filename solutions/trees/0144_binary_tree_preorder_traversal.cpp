class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* node) {
        if (node == nullptr)
            return;

        result.push_back(node->val);

        preorder(node->left);
        preorder(node->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};