class Solution {
public:
    vector<string> result;

    void dfs(TreeNode* node, string path) {
        if (node == nullptr)
            return;

        if (!path.empty())
            path += "->";

        path += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }

        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};