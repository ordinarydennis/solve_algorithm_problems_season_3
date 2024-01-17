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

    TreeNode* dfs(int begin, int end, vector<int>& nums)
    {
        if (end < begin)
        {
            return nullptr;
        }

        int max = INT_MIN;

        int index = begin;

        for (int i = begin; i <= end; i++)
        {
            if (max < nums[i])
            {
				max = nums[i];
                index = i;
            }
        }

        auto* node = new TreeNode(max);

        node->left = dfs(begin, index - 1, nums);
        node->right = dfs(index + 1, end, nums);

        return node;
    }


public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return dfs(0, nums.size() - 1, nums);

    }
};