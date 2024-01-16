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


class Solution {
public:

	// function for find height of tree

	int height(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int left_height = height(root->left);

		int right_height = height(root->right);

		return 1 + max(left_height, right_height);
	}

	vector<vector<string>> printTree(TreeNode* root) {

		// find height of tree

		int h = height(root);

		h--;

		// n = no. of rows

		int n = h + 1;

		// m = no. of columns

		int m = pow(2, h + 1) - 1;

		// declare a res matrix

		vector<vector<string>> res(n, vector<string>(m, ""));

		// apply bfs

		// declare a queue

		queue<pair<TreeNode*, pair<int, int>>> q;

		// push the root into queue

		q.push({ root, {0, (m - 1) / 2} });

		while (!q.empty())
		{
			// take outh the front node

			auto curr = q.front();

			q.pop();

			// find row no.

			int r = curr.second.first;

			// find col. no.

			int c = curr.second.second;

			// find curr_node

			TreeNode* curr_node = curr.first;

			// put the value at its position in res

			res[r][c] = to_string(curr_node->val);

			// push the left node into queue

			if (curr_node->left)
			{
				q.push({ curr_node->left, {r + 1, c - pow(2, h - 1 - r)} });
			}

			// push the right node into queue

			if (curr_node->right)
			{
				q.push({ curr_node->right, {r + 1, c + pow(2, h - 1 - r)} });
			}
		}

		return res;
	}
};

//https://leetcode.com/problems/print-binary-tree/solutions/2409429/faster-easy-to-understand-c-code/
