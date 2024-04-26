class Solution {

	vector<vector<int>> ret;

	bool dfs(int index, vector<int>& nums, vector<int> nlist, vector<bool>& visit, int count, int pre)
	{
		if (3 <= nlist.size())
		{
			ret.push_back(nlist);
			return true;
		}

		for (int i = index; i < nums.size(); i++)
		{
			if (visit[i])
			{
				continue;
			}

			if (0 < index && nums[i] != pre + 1)
			{
				continue;
			}

			visit[i] = true;

			nlist.push_back(nums[i]);

			if (dfs(i + 1, nums, nlist, visit, count + 1, nums[i]))
			{
				count = 0;
				nlist.clear();
			}
			else
			{
				nlist.pop_back();
			}

		}

		return false;
	}


public:
	bool isPossible(vector<int>& nums) {

		vector<bool> visit(nums.size(), false);

		vector<int>  nlist;

		dfs(0, nums, nlist, visit, 0, 0);

		int sum = 0;

		for (auto& v : ret)
		{
			sum += v.size();
		}

		return 1 < ret.size() || nums.size() == sum;

	}
};