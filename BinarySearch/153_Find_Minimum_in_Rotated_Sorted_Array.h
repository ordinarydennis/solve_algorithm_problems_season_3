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

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int low = 0, high = n - 1;

		while (low < high) {
			if (nums[low] <= nums[high]) 
				return nums[low];

			int mid = low + (high - low) / 2;

			//search for unaligned sections
			//the minimum value is in unaligned section
			if (nums[low] > nums[mid])
			{
				high = mid; //including mid because mid could be the minimum value
			}
			else if (nums[mid] > nums[high])
			{
				low = mid + 1;
			}
		}
		if (nums[low] <= nums[high]) 
			return nums[low];

		return -1;
	}
};