class Solution {


	int maxSize = INT_MIN;

	vector<string> ret;

	void dfs(int preGroupId, int curIndex, vector<string>& words, vector<int>& groups, vector<string>& strList)
	{
		if (curIndex == words.size())
		{
			if (strList.size() < maxSize)
				return;
			
			maxSize = static_cast<int>(strList.size());

			ret = strList;

			return;
		}

		for (int i = curIndex; i < words.size(); i++)
		{
			if (groups[i] == preGroupId)
			{
				continue;
			}

			strList.push_back(words[i]);

			dfs(groups[i], i + 1, words, groups, strList);

			strList.pop_back();
		}
	}


public:
	vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

		vector<string> strList;

		dfs(2, 0, words, groups, strList);

		return	ret;
	}
};

//https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/solutions/4168304/c-c-java-python-javascript-beats-95-dp-explained/

class Solution {
public:
	vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
		// Initialize two vectors to keep track of the maximum subsequence length and the previous word index.
		vector<int> dp(groups.size(), 1);
		vector<int> pv(groups.size(), -1);

		// Iterate through the words and groups to find the longest subsequence.
		for (int i = 1; i < groups.size(); i++) {
			for (int j = 0; j < i; j++) {
				// Check if the groups are different.
				if (groups[i] == groups[j]) continue;

				// If the subsequence length of j + 1 is greater than i, update dp[i] and pv[i].
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					pv[i] = j;
				}
			}
		}

		// Find the index of the maximum subsequence length in the dp vector.
		int wi = (max_element(dp.begin(), dp.end()) - dp.begin());
		vector<string> ans; // Initialize a vector to store the answer.

		// Reconstruct the longest subsequence by following the previous word indices.
		while (wi != -1) {
			ans.push_back(words[wi]); // Add words to the answer in reverse order to get the longest subsequence.
			wi = pv[wi]; // Move to the previous word in the subsequence.
		}

		reverse(ans.begin(), ans.end()); // Reverse the answer to get the correct order.
		return ans;
	}
};



class Solution {
public:
	vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

		vector<int> pre(words.size(), -1);
		vector<int> count(words.size(), 1);

		for(int a = 1; a  < groups.size(); a++)
		{ 
			for (int i = 0; i < a; i++)
			{
				if (groups[i] == groups[a])
					continue;

				if (count[a] < count[i] + 1)
				{
					pre[a] = i;
					count[a] = count[i] + 1;
				}	
			}
		}

		int index = max_element(count.begin(), count.end()) - count.begin();

		vector<string> ret;

		while (-1 != index)
		{
			ret.push_back(words[index]);
			index = pre[index];
		}

		reverse(ret.begin(), ret.end());
		
		return ret;
	}
};
