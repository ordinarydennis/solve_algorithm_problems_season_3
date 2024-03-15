class Solution {

	std::unordered_map<int, int> memo;

	int dfs(int n, vector<int>& cost)
	{
		if (cost.size() <= n)
			return 0;

		if (memo.count(n))
			return memo[n];

		return memo[n] = std::min(dfs(n + 1, cost), dfs(n + 2, cost)) + cost[n];
	}


public:
	int minCostClimbingStairs(vector<int>& cost) {

		return std::min(dfs(0, cost), dfs(1, cost));

	}
};