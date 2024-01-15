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
class Solution {

	void traversal(TreeNode* root, vector<int>& list, int& h)
	{
		if (!root)
		{
			return;
		}

		int temp = h;

		if (root->left)
		{
			list.push_back(root->left->val);
			traversal(root->right);
			h++;
		}

		if (root->right)
		{
			list.push_back(root->right->val);
			traversal(root->right);
			if (temp == h)
			{
				h++;
			}
		}
	}

public:
	vector<vector<string>> printTree(TreeNode* root) {

		vector<int> list;

		list.push_back(root->val);

		traversal(root, list, h);

		vector<vector<string>> mat(h, vector<string>(list.size()));

		int row = 0;
		int c = list.size();


		mat[row][c / 2] = list[0];

		for (int i = 0; i < list.size(); i++)
		{

		}
		
	}
};