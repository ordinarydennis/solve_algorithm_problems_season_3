class Solution {
public:
	int findPairs(vector<int>& nums, int k) {

		std::set<std::pair<int, int>> memo;

		int ret = 0;

		for (int a = 0; a < nums.size() - 1; a++)
		{
			for (int b = a + 1; b < nums.size(); b++)
			{
				auto p1 = std::pair<int, int>{ nums[a], nums[b] };
				auto p2 = std::pair<int, int>{ nums[b], nums[a] };

				if (memo.count(p1) || memo.count(p2))
					continue;

				if (k == std::abs(nums[a] - nums[b]))
				{
					memo.insert(p1);
					memo.insert(p2);
					ret++;
				}
			}
		}


		return ret;

	}
};

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {

		std::sort(nums.begin(), nums.end());

		int ret = 0;

		std::set<std::pair<int, int>> memo;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (memo.count(pair<int, int>{ nums[i], nums[i] + k }))
				continue;
			
			if (nums.end() != find(nums.begin() + i + 1, nums.end(), nums[i] + k))
			{
				ret++;
				memo.insert(pair<int, int>{ nums[i], nums[i] + k });
			}
			
		}

		return ret;
	}
};