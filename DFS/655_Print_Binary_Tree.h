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

	int GetTreeHeight(TreeNode* root, int h)
	{
		if (nullptr == root)
		{
			return h;
		}

		h++;

		return std::max(GetTreeHeight(root->left, h), GetTreeHeight(root->right, h));
	}

	struct Node
	{
		TreeNode* root = nullptr;
		int row = 0;
		int column = 0;

		Node(TreeNode* node, int r, int c)
			:root(node), row(r), column(c)
		{

		}
	};

public:
    vector<vector<string>> printTree(TreeNode* root) {

		int h = 0;

		h = GetTreeHeight(root, h);

		int n = pow(2, h) - 1;

		vector<vector<string>> ret(h, vector<string>(n));

		std::queue<Node> q;

		int cI = (n - 1) / 2;
		int rI = 0;

		q.push( Node{ root, rI, cI } );

		while (q.size())
		{
			auto node = q.front();

			q.pop();

			ret[node.row][node.column] = to_string(node.root->val);

			rI = node.row;
			cI = node.column;

			if(node.root->left)
			{
				q.push(Node{ node.root->left, rI + 1, static_cast<int>(cI - pow(2, h - rI - 1)) });
			}

			if (node.root->right)
			{
				q.push(Node{ node.root->right, rI + 1, static_cast<int>(cI + pow(2, h - rI - 1)) });
			}	
		}

		return ret;
    }
};