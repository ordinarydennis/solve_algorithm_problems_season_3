class Solution {
public:
	int minOperations(vector<int>& nums) {

		std::unordered_map<int, int> memo;

		for (int n : nums)
		{
			memo[n]++;
		}

		int ret = 0;

		for (auto& [n , c] : memo)
		{
			if (c % 3 == 0)
			{
				ret += c / 3;
			}
			else if (3 < c)
			{
				if (c % 3 == 1 || c % 3 == 2)
				{
					ret += (c / 3) + 1;
				}
			}
			else if (c % 3 == 2)
			{
				ret += 1;
			}
			else
			{
				return -1;
			}
		}

		return ret;
	}
};