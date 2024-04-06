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

	struct Node
	{
		TreeNode* root;
		int r;
		int c;
	};

	int GetHeight(TreeNode* root, int h)
	{
		if (nullptr == root)
		{
			return h;
		}

		h++;

		return max(
			GetHeight(root->left, h),
			GetHeight(root->right, h)
		);
	}

	int GetHeightBfs(TreeNode* root)
	{
		queue<TreeNode*> q;
		q.push(root);

		int h = 0;

		while (q.size())
		{
			h++;

			int s = q.size();

			while (s--)
			{
				auto node = q.front();

				q.pop();

				if (node->left)
					q.push(node->left);

				if (node->right)
					q.push(node->right);
			}
		}

		return h;
	}


public:
	vector<vector<string>> printTree(TreeNode* root) {

		int h = GetHeightBfs(root) - 1;
		int n = pow(2, h + 1) - 1;

		vector<vector<string>> ret(h + 1, vector<string>(n));

		queue<Node> q;

		q.push(Node{ root, 0, (n - 1) / 2 });

		while(q.size())
		{ 
			auto node = q.front();
			q.pop();

			ret[node.r][node.c] = to_string(node.root->val);

			if (node.root->left)
			{
				int c = node.c - pow(2, h - node.r - 1);
				q.push(Node{ node.root->left, node.r + 1, c });
			}

			if (node.root->right)
			{
				int c = node.c + pow(2, h - node.r - 1);
				q.push(Node{ node.root->right, node.r + 1, c });
			}
		}

		return ret;
	}
};