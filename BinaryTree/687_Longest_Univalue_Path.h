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

private:
	int ret;

	int dfs(TreeNode* root, int val)
	{
		if (nullptr == root)
			return 0;

		int l = dfs(root->left, root->val);
		int r = dfs(root->right, root->val);

		ret = std::max(ret, l + r);

		return (root->val == val) ? max(l, r) + 1 : 0;
	}

public:
	int longestUnivaluePath(TreeNode* root) {

		dfs(root, -1001);

		return ret;
	}
};


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

	int ret = 0;

	int dfs(TreeNode* root, int pv)
	{
		if (nullptr == root)
			return 0;

		int ll = dfs(root->left, root->val);
		int rl = dfs(root->right, root->val);

		ret = std::max(ret,  ll + rl);

		return pv == root->val ? std::max(ll, rl) + 1 : 0;
	}

public:
	int longestUnivaluePath(TreeNode* root) {

		dfs(root, -1);

		return ret;

	}
};