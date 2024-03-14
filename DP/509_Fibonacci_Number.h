//dfs
class Solution {

	int dfs(int n)
	{
		if (n <= 1)
			return n;

		return dfs(n - 1) + dfs(n - 2);
	}


public:
	int fib(int n) {

		return dfs(n);

	}
};

//dp bottom up
class Solution {

public:
	int fib(int n) {

		if (n <= 1)
			return n;

		int a = 0;
		int b = 1;

		int ret = 0;

		int index = 1;

		while (index < n)
		{
			ret = a + b;

			a = b;
			b = ret;

			index++;
		}

		return ret;
	}
};


//dp top down
class Solution {

	std::unordered_map<int, int> memo;

	int dfs(int n)
	{
		if (memo.count(n))
			return memo[n];

		if (n <= 1)
			return n;


		int a = dfs(n - 1);
		int b = dfs(n - 2);

		memo[n] = a + b;

		return a + b;
	}


public:
	int fib(int n) {

		return dfs(n);

	}
};