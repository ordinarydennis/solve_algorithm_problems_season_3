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

	bool dfs(TreeNode* root1, TreeNode* root2)
	{
		if (root1->left && root1->right)
		{
			if (!root2->left || !root2->right)
			{
				return false;
			}
		}

		if (root2->left && root2->right)
		{
			if (!root1->left || !root1->right))
			{
				return false;
			}
		}
		
		if (root1->left.val == root2->right.val)
		{
			if (false == dfs(root1->left, root2->right))
			{
				return false;
			}
		}

		if (root1->right.val == root2->left.val)
		{
			if (false == dfs(root1->right, root2->left))
			{
				return false;
			}
		}

		if (root1->left.val == root2->left.val)
		{
			if (false == dfs(root1->left, root2->left))
			{
				return false;
			}

		}

		if (root1->right.val == root2->right.val)
		{
			if (false == dfs(root1->right, root2->right))
			{
				return false;
			}
		}

		
		return true;
	}


public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {



	}
};