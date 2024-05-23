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