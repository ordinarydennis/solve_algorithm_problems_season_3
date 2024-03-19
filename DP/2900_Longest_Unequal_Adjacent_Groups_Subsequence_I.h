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