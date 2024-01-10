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

class Solution {
	public boolean flipEquiv(TreeNode root1, TreeNode root2) {
		if (root1 == root2)
			return true;
		if (root1 == null || root2 == null || root1.val != root2.val)
			return false;

		return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right) ||
			flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
	}
}

class Solution {

	//check the value of two childs are same or not

public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {

		//if both are nullptr
		if (!root1 && !root2)
			return true;

		if (nullptr == root1)
		{
			return false;
		}

		if (nullptr == root2)
		{
			return false;
		}

		if (root1->val != root2->val)
		{
			return false;
		}

		bool r1 = flipEquiv(root1->left, root2->left);
		bool r2 = flipEquiv(root1->right, root2->right);

		if (r1 && r2)
		{
			return true;
		}

		bool r3 = flipEquiv(root1->left, root2->right);
		bool r4 = flipEquiv(root1->right, root2->left);
		if (r3 && r4)
		{
			return true;
		}

		return false;
	}
};