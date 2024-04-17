class Solution {

	void cacheString(string& s, std::unordered_map<string, int>& m)
	{
		string ss;

		for (int i = 0; i <= s.size(); i++)
		{
			if (i == s.size() || ' ' == s[i])
			{
				if (ss.size())
				{
					m[ss]++;

					ss.clear();
				}
			}
			else
			{
				ss += s[i];
			}
		}
	}


public:
	vector<string> uncommonFromSentences(string s1, string s2) {

		std::unordered_map<string, int> m;

		cacheString(s1, m);
		cacheString(s2, m);

		vector<string> ret;

		for (auto& [str, count] : m)
		{
			if (1 == count)
			{
				ret.push_back(std::move(str));
			}
		}

		return ret;
	}
};