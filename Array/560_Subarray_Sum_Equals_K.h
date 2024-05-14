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