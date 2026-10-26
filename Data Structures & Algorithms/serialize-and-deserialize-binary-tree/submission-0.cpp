/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        preorder(root, data);
        return data;
    }
    void preorder(TreeNode* root, string& data) {
        if (!root) {
            data += "N,";
            return;
        }

        data += to_string(root->val) + ",";

        preorder(root->left, data);
        preorder(root->right, data);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            vals.push_back(token);
        }

        int i = 0;
        return build(vals, i);
    }

    TreeNode* build(vector<string>& vals, int& i) {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(vals[i]));
        i++;

        root->left = build(vals, i);
        root->right = build(vals, i);

        return root;
    }
};
