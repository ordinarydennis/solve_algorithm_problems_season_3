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