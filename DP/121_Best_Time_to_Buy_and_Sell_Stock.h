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

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/3169837/best-c-3-solution-dp-space-optimization-brute-force-optimize/
/*

	Time Complexity : O(N^2), Where N is the size of the Array(prices). As we check for possible pair, and the
	total number of pairs are : N*(N–1)/2.

	Space complexity : O(1), Constant space.

	Using Array(Two Nested Loop). Brute Force Approach.

	Note : This will give TLE.

*/


/***************************************** Approach 1 Code *****************************************/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size(), maxProfit = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (prices[j] - prices[i] > maxProfit) {
					maxProfit = prices[j] - prices[i];
				}
			}
		}
		return maxProfit;
	}
};






/*

	Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

	Space complexity : O(N), Array(maxPrices) space.

	Solved using Dynamic Programming Approach(tabulation).

*/


/***************************************** Approach 2 Code *****************************************/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> maxPrices(n, 0);
		maxPrices[n - 1] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			maxPrices[i] = max(maxPrices[i + 1], prices[i]);
		}
		int maxProfit = 0;
		for (int i = 0; i < n; i++) {
			maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
		}
		return maxProfit;
	}
};






/*

	Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

	Space Complexity : O(1), Constant space.

	Solved using Dynamic Programming Approach(Space optimisation).

*/


/***************************************** Approach 3 Code *****************************************/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int buyAtPrice = INT_MAX;
		int maxProfit = 0;
		for (int i = 0; i < n; i++) {
			buyAtPrice = min(buyAtPrice, prices[i]);
			maxProfit = max(maxProfit, prices[i] - buyAtPrice);
		}
		return maxProfit;
	}
};


//Solved again 03.24 
//Time complexity O(n)
//Space complexity O(n)
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		vector<int> dp(prices.size(), INT_MAX);

		dp[0] = prices[0];

		int ret = 0;

		for (int i = 1;i < prices.size(); i++)
		{
			ret = max(ret, prices[i] - dp[i - 1]);
			
			dp[i] = min(dp[i - 1], prices[i]);
		}

		return ret;
	}
};

//Solved again 03.24 
//Time complexity O(n)
//Space complexity O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int min = INT_MAX;

		int ret = 0;

		for (int i = 0; i < prices.size(); i++)
		{
			min = std::min(min, prices[i]);
			ret = max(ret, prices[i] - min);
		}

		return ret;
	}
};