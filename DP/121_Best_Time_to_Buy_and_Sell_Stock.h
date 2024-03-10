class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int ret = 0;

		for (int b = 0; b < prices.size() - 1; b++)
		{
			for (int s = b + 1; s < prices.size(); s++)
			{
				ret = max(ret, prices[s] - prices[b]);
			}
		}

		return ret;
	}
};