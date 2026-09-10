class Solution {
public:
    vector<int> result;

    void postorder(TreeNode* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);

        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return result;
    }
};