class Solution {
public:
    int count = 0;
    int answer = 0;

    void inorder(TreeNode* node, int k) {
        if (node == nullptr)
            return;

        inorder(node->left, k);

        count++;

        if (count == k) {
            answer = node->val;
            return;
        }

        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }
};