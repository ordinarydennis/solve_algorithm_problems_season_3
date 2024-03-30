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

	TreeNode* deserialize(istringstream& iss)
	{
		string val;

		iss >> val;

		if ("#" == val)
			return nullptr;
	   
		auto* node = new TreeNode(stoi(val));
		node->left = deserialize(iss);
		node->right = deserialize(iss);
		
		return node;
	}

public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

		if (nullptr == root)
			return "# ";

		return 
			std::to_string(root->val)   + " " + 
			serialize(root->left)       + " " + 
			serialize(root->right)      + " " ;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

		istringstream iss(data);

		return deserialize(iss);

	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

//the tree will be serialized as follow:
//    5
//  2   6
// 1 3

//"5 2 1 # # 3 # # 6 # # "


