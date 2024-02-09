class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {

		int ret = INT_MIN;

		for (int size = 0; size < nums.size(); size++)
		{
			for (int cur = 0; cur < nums.size(); cur++)
			{
				int sum = 0;

				for (int start = cur; start <= cur + size; start++)
				{
					sum += nums[(start) % nums.size()];
				}

				ret = std::max(ret, sum);
			}
		}

		return ret;
	}
};