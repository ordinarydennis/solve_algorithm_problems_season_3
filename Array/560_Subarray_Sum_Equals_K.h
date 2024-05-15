class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int n = nums.size();

		int ret = 0;

		for (int s = 0; s < n; s++)
		{
			for (int e = s + 1; e <= n; e++)
			{
				int sum = std::accumulate(nums.begin() + s, nums.begin() + e, 0);

				if (sum == k)
				{
					ret++;
				}
			}
		}

		return ret;
	}
};


class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int n = nums.size();

		std::vector<int> sum(n + 1);

		for (int i = 1; i <= nums.size(); i++)
		{
			sum[i] = sum[i - 1] + nums[i - 1];
		}

		int ret = 0;

		for (int s = 0; s < nums.size(); s++)
		{
			for (int e = s + 1; e <= nums.size(); e++)
			{
				if (sum[e] - sum[s] == k)
				{
					ret++;
				}
			}
		}

		return ret;
	}

};




class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int start = 0;

		int sum = 0;

		int ret = 0;

		for(int i = 0; i < nums.size(); i++)
		{ 
			sum += nums[i];

			if (sum == k)
			{
				ret++;

				sum -= nums[start];

				start++;
			}
			else if (k != sum)
			{
				if (k < sum)
				{
					while (k < sum && start < nums.size())
					{
						sum -= nums[start];
						start++;
					}
				}
				else
				{
					while (sum < k  && i < nums.size())
					{
						sum += nums[i];
						i++;
					}
				}

				if (k == sum)
				{
					ret++;
				}
			}
		}

		return ret;
	}
};