
//bottom-up
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		vector<int> dp(arr.size() + 1);

		for (int start = arr.size() - 1; 0 <= start; start--)
		{
			int end = min(start + k, static_cast<int>(arr.size()));

			int maxValue = 0;

			for (int i = start; i < end; i++)
			{
				maxValue = max(maxValue, arr[i]);

				dp[start] = max(
					dp[start],
					dp[i + 1] + maxValue * (i - start + 1)
				);
			}
		}

		return dp[0];
	}
};


//top-down
class Solution {

	int dfs(vector<int>& dp, int start, vector<int>& arr, int k)
	{
		if (arr.size() <= start)
		{
			return 0;
		}

		if (-1 != dp[start])
		{
			return dp[start];
		}

		int end = min(start + k, static_cast<int>(arr.size()));

		int maxValue = 0;

		int ret = 0;

		for (int i = start; i < end; i++)
		{
			maxValue = max(maxValue, arr[i]);

			ret = max(
				ret,
				maxValue * (i - start + 1) + dfs(dp, i + 1, arr, k)
			);
		}

		return dp[start] = ret;
	}

public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		vector<int> dp(arr.size(), -1);

		return dfs(dp, 0, arr, k);

	}
};



class Solution {

	int dfs(int start, vector<int>& arr, int k)
	{
		int ret = 0;

		for (int i = k; 1 <= i; i--)
		{
			if (arr.size() <= start + i)
			{
				break;
			}

			auto mIt = max_element(arr.begin() + start, arr.begin() + start + i);
			
			int sum = *mIt * i;
			
			int r = 0;

			r = dfs(start + i, arr, k) + sum;

			ret = std::max(ret, r);

		}

		return ret;
	}

public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {

		return dfs(0, arr, k);

	}
};