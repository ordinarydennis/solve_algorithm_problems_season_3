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


class Solution {

	int dfs(int n)
	{
		if (n <= 1)
			return 1;

		return dfs(n - 1) + dfs(n - 2);
	}


public:
	int climbStairs(int n) {

		return dfs(n);
	}
};

class Solution {


public:
	int climbStairs(int n) {

		vector<int> memo(n + 1);

		memo[0] = 1;
		memo[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			memo[i] = memo[i - 1] + memo[i - 2];
		}

		return memo[n];
	}
};

https://leetcode.com/problems/climbing-stairs/solutions/3708750/4-method-s-beat-s-100-c-java-python-beginner-friendly/
