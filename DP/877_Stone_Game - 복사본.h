class Solution {
public:
	bool stoneGame(vector<int>& piles) {

		int sumA = 0;
		int sumB = 0;

		bool isA = true;

		int start = 0;
		int end = piles.size() - 1;

		while (start <= end)
		{
			int max = 0;

			if (piles[start] < piles[end])
			{
				max = piles[start];
				start++;
			}
			else
			{
				max = piles[end];
				end--;
			}

			if (isA)
			{
				sumA += max;
			}
			else
			{
				sumB += max;
			}
		}

		return sumB < sumA;

	}
};

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		vector<vector<int>>dp(n, vector<int>(n));

		for (int gap = 0; gap < n; gap++)
		{
			for (int i = 0, j = gap; j < n; i++, j++) {
				if (gap == 0)
				{
					dp[i][j] = piles[i];
				}

				else if (gap == 1)
				{
					dp[i][j] = max(piles[i], piles[j]);
				}
				else
				{
					int case1 = piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
					int case2 = piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
					dp[i][j] = max(case1, case2); // maximum of these 2 cases
				}
			}
		}

		return dp[0][n - 1];
	}
};