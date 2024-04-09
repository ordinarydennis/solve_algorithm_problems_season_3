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

	TreeNode* ReConstructTree(TreeNode* root, int low, int high)
	{
		if (nullptr == root)
		{
			return nullptr;
		}

		if (root->val < low || high < root->val)
		{
			if (root->left && root->right)
			{
				auto* l = root->right;
				auto* pre = root;
				auto* mostL = root;
				while (l)
				{
					pre = mostL;
					mostL = l;
					l = l->left;
				}

				auto* curL = root->left;
				auto* curR = root->right;

				root = mostL;

				if (root->left->val < mostL->val)
				{
					root->left = curL;
					root->right = curR;
					pre->left = nullptr;
				}
				else
				{
					root->right = nullptr;
				}
				
			}
			else if (root->left)
			{
				root = root->left;
			}
			else if (root->right)
			{
				//부모와 비교해야한다?
				root = root->right;
			}
			else
			{
				root = nullptr;
			}
		}

		root->left = ReConstructTree(root->left, low, high);
		root->right = ReConstructTree(root->right, low, high);

		return root;
	}


public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {

		return ReConstructTree(root, low, high);

	}
};


