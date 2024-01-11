class Solution {

	int dfs(int start, int end, vector<int>& nums)
	{
		if (nums[start] <= nums[end])
		{
			return nums[start];
		}

		if (end < start)
		{
			return INT_MAX;
		}

		int mid = (start + end) / 2;

		int ret = std::min(
			dfs(start, mid, nums),
			dfs(mid + 1, end, nums)
		);
		
		return ret;
	}


public:
	int findMin(vector<int>& nums) {

		return dfs(0, nums.size() - 1, nums);
		

	}
};


class Solution {

	int dfs(int start, int end, vector<int>& nums)
	{
		if (start == end)
		{
			return nums[start];
		}

		if (end < start)
		{
			return INT_MAX;
		}

		int mid = (start + end) / 2;

		int ret = std::min(
			dfs(start, mid, nums),
			dfs(mid + 1, end, nums)
		);

		return ret;
	}


public:
	int findMin(vector<int>& nums) {

		return dfs(0, nums.size() - 1, nums);


	}
};