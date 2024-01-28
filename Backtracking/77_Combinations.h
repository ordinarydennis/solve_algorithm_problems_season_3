class Solution {

	vector<vector<int>> ret;

	void dfs(int index, int n,  int k, int count, vector<int>& result)
	{
		if (k == count)
		{
			ret.push_back(result);
			return;
		}

		for (int i = index + 1; i <= n; i++)
		{
			result.push_back(i);
			dfs(i, n, k, count + 1, result);
			result.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {

		vector<int> result;

		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			result.push_back(i);
			dfs(i, n, k, count + 1, result);
			result.pop_back();
		}

		return ret;
	}
};