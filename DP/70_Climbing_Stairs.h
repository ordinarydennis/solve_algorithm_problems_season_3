class Solution {

	int ret = 0;

	unordered_map<int, int> memo;

	bool dfs(int n)
	{
		if (n < 0)
			return true;

		if (n == 0)
		{
			ret++;
			return true;
		}

		for (int i = 1; i <= 2; i++)
		{
			if (dfs(n - i))
			{
				break;
			}
		}

		return false;
	}


public:
	int climbStairs(int n) {

		dfs(n);

		return ret;
	}
};