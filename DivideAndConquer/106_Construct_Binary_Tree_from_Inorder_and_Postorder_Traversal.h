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

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> index;
		for (int i = 0; i < inorder.size(); i++) {
			index[inorder[i]] = i;
		}
		return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
	}

	TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int>& index) {
		if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
			return nullptr;
		}
		int rootVal = postorder[postorderEnd];
		TreeNode* root = new TreeNode(rootVal);
		int inorderRootIndex = index[rootVal];
		int leftSubtreeSize = inorderRootIndex - inorderStart;
		root->left = buildTreeHelper(inorder, postorder, inorderStart, inorderRootIndex - 1, postorderStart, postorderStart + leftSubtreeSize - 1, index);
		root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderEnd, postorderStart + leftSubtreeSize, postorderEnd - 1, index);
		return root;
	}
};

//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/3302159/easy-solutions-in-java-python-and-c-look-at-once/


root node of the left sub tree is the last element between begin and end of postorder arr
the range of left sub tree in postorder arr is from begin to rootIndexIn - 1 of postorder arr

Input : inorder = [8, 9, 10, 3, 15, 20, 7], postorder = [8, 10, 9, 15, 7, 20, 3]

                   3
inorder    8 9 10     15 20 7
				   
postorder  8 10 9     15 7 20   3
the search range of postorder arr IN next sub tree is from start of post orderr arr to start + leftSubtreeSize - 1 IN inorder arr
What is the last element of postorder arr?
It is root node of the inorder arr
so, What is the first element of postorder arr?
It is most left node of the inorder arr.

	