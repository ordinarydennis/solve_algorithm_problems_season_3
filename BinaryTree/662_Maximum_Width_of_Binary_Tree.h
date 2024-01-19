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

		while(!q.empty())
		{
			int size = static_cast<int>(q.size());
			int nulCount = 0;
			int intCount = 0;
			int sum = 0;

			for(int i = 0; i < size; i++)
			{
				auto f = q.front();
				q.pop();

				if(!f)
				{
					continue;
				}

				q.push(f->left);

				q.push(f->right);

				if(f->left)
				{
					sum++;
					sum += nulCount;
					nulCount = 0;
				}
				else
				{
					nulCount++;
				}
				
				if(f->right)
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