class Solution {
public:
	int shortestDistance(vector<string>& wordsDict, string word1, string word2) {

		unordered_map<string, vector<int>> m;

		for (int i = 0; i < wordsDict.size(); i++)
		{
			if (wordsDict[i] == word1 || wordsDict[i] == word2)
			{
				m[wordsDict[i]].push_back(i);
			}
		}

		auto v1 = m[word1];
		auto v2 = m[word2];

		int ret = INT_MAX;

		for (int a = 0; a < v1.size(); a++)
		{
			for (int b = 0; b < v2.size(); b++)
			{
				ret = min(ret, std::abs(v1[a] - v2[b]));
			}
		}

		return ret;
	}
};