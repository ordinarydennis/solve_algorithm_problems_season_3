class Solution {
public:
	int triangleNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		int ret = 0;

		int n = nums.size();

		for (int a = 0; a < n - 2; a++)
		{
			for (int b = a + 1; b < n - 1; b++)
			{
				for (int c = b + 1; c < n; c++)
				{
					if (nums[c] < nums[a] + nums[b])
					{
						ret++;
					}		
				}
			}
		}

		return ret;
	}
};