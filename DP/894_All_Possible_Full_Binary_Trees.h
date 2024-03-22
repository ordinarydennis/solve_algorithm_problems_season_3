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

	TreeNode* dfs(int n)
	{
		if (n <= 0)
		{
			return nullptr;
		}

		TreeNode* node = new TreeNode;

		node->left = dfs(n--);
		node->right = dfs(n--);

		return node;
	}


public:
	vector<TreeNode*> allPossibleFBT(int n) {

		//0, 1, 2, 3, 4,5,6

		return dfs(n);

	}
};
