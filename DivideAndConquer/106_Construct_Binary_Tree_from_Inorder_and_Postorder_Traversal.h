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

	TreeNode* divide (vector<int>& inorder, int begin, int end, vector<int>& postorder, int rootIndexPost)
	{
		if(end == begin)
		{
			return nullptr;
		}

		int rootIndexIn = 0;

		for(int i = begin; i < end; i++)
		{
			if(postorder[rootIndexPost] == inorder[i])
			{
				rootIndexIn = i;
				break;
			}
		}

		TreeNode* root = new TreeNode(inorder[rootIndexIn]);

		root->right = divide(inorder, rootIndexIn + 1, end, postorder, rootIndexPost--);
		
		root->left = divide(inorder, begin, rootIndexIn, postorder, rootIndexPost--);
		
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		int rootIndexPost = inorder.size() - 1;
		int rootIndexIn = 0;

		for(int i = 0; i < inorder.size(); i++)
		{
			if(postorder[rootIndexPost] == inorder[i])
			{
				rootIndexIn = i;
				break;
			}
		}

		TreeNode* root = new TreeNode(inorder[rootIndexIn]);

		root->right = divide(inorder, rootIndexIn + 1, inorder.size(), postorder, rootIndexPost--);

		root->left = divide(inorder, 0, rootIndexIn, postorder, rootIndexPost--);

		return  root;
    }
};