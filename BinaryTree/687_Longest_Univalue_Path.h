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

	int dfs(TreeNode* root, int l)
	{
		int leftL = 0;
		int rightL = 0;

		if (root->left)
		{
			leftL = (root->val == root->left->val) ? dfs(root->left, ++l) : dfs(root->left, 0);
		}

		if (root->right)
		{
			rightL = (root->val == root->right->val) ? dfs(root->right, ++l) : dfs(root->right, 0);
		}
		
		if (root->left && root->right)
		{
			if (root->val == root->left->val && 
				root->left->val == root->right->val)
			{
				return rightL;
			}
		}

		return std::max(l, std::max(leftL, rightL));
	}


public:
	int longestUnivaluePath(TreeNode* root) {

		if (nullptr == root)
		{
			return 0;
		}

		return dfs(root, 0);

	}
};