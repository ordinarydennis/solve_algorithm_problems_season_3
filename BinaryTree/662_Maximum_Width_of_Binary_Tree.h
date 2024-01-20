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

public:
	int widthOfBinaryTree(TreeNode* root) {

		queue<TreeNode*> q;

		q.push(root);

		int ret = 0;

		while (!q.empty())
		{
			int size = static_cast<int>(q.size());
			int nulCount = 0;
			int intCount = 0;
			int sum = 0;

			for (int i = 0; i < size; i++)
			{
				auto f = q.front();
				q.pop();

				if (!f)
				{
					continue;
				}

				q.push(f->left);

				q.push(f->right);

				if (f->left)
				{
					sum++;
					sum += nulCount;
					nulCount = 0;
				}
				else
				{
					nulCount++;
				}

				if (f->right)
				{
					sum++;
					sum += nulCount;
					nulCount = 0;
				}
				else
				{
					nulCount++;
				}
			}

			ret = std::max(ret, sum);

		}
		return ret;
	}
};


class Solution {

public:
	int widthOfBinaryTree(TreeNode* root) {

		queue<pair<TreeNode*, long long>> que;

		que.push({ root, 0 });

		int ret = 0;

		while (que.size())
		{
			int sz = static_cast<int>(que.size());

			auto first = que.front().second;

			int begin = 0;
			int end = 0;

			for (int i = 0; i < sz; i++)
			{
				auto p = que.front();
				que.pop();

				auto k = p.second - first;

				if (0 == i)
				{
					begin = k;
				}

				if (sz - 1 == i)
				{
					end = k;
				}

				if (p.first->left)
				{
					que.push({ p.first->left , (2 * k) + 1 });
				}
				if (p.first->right)
				{
					que.push({ p.first->right , (2 * k) + 2 });
				}
			}

			ret = std::max(ret, end - begin + 1);
		}

		return ret;
	}
};


//https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/3436483/c-bfs-approach-with-explanation-simple-solution/
