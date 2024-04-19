class Solution {

	bool isNice(string& s)
	{
		std::unordered_map<int, pair<bool, bool>> arr;

		for (char c : s)
		{
			if ('a' <= c && c <= 'z')
			{
				arr[c - 'a'].first = true;
			}
			else
			{
				arr[c - 'A'].second = true;
			}
		}

		for (auto& [_, pair] : arr)
		{
			if (false == pair.first || false == pair.second)
			{
				return false;
			}
		}

		return true;
	}


public:
	string longestNiceSubstring(string s) {

		string ret;

		for (int i = 0; i < s.size() - 1; i++)
		{
			for (int l = 2; l <= s.size() - i; l++)
			{
				auto sub = s.substr(i, l);
				if (isNice(sub))
				{
					if (ret.size() < l)
					{
						ret = sub;
					}
				}
			}
		}

		return ret;
	}
};