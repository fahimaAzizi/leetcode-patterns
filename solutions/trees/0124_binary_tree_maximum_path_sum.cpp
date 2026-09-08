class Solution {
public:
    int maxSum = INT_MIN;

    int findMaxPath(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left = max(0, findMaxPath(node->left));
        int right = max(0, findMaxPath(node->right));

        int currentPath = node->val + left + right;

        maxSum = max(maxSum, currentPath);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return maxSum;
    }
};