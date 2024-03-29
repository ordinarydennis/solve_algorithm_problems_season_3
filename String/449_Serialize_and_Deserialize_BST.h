/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {


    void serializeDfs(TreeNode* root, string& out)
    {
        if (!root)
            return;

        out += to_string(root->val);

        serializeDfs(root->left, out);
        serializeDfs(root->right, out);
    }


	void deserializeDfs(const string& data, int index, TreeNode* out)
	{
		if (!out)
			return;

        out = new TreeNode(data[index] - '0');

        out->left = deserializeDfs(data, index++, out);
        out->right = deserializeDfs(data, index++, out);
	}

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ret;

        serializeDfs(root, ret);


        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        TreeNode* ret = new TreeNode();

        deserializeDfs(data, 0, ret);

        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;