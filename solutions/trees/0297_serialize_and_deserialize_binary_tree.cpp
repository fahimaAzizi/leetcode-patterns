class Codec {
public:
    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string value;
        getline(ss, value, ',');

        if (value == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(value));

        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};