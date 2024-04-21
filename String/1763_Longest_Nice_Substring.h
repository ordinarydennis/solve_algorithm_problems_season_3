class Solution {

	bool isNice(string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			char c = islower(str[i]) ? (str[i] - 'a') + 'A' : (str[i] - 'A') + 'a';
			if (str.find(c) == string::npos)
				return false;
		}
		return true;
	}

public:
	string longestNiceSubstring(string s) {

		string ret;

		for (int a = 0; a < s.size(); a++)
		{
			string str = string(1, s[a]);
			for (int b = a + 1; b < s.size(); b++)
			{
				if (str += s[b]; isNice(str) && ret.size() < str.size())
					ret = str;
			}
		}

		return ret;
	}
};
https://leetcode.com/problems/longest-nice-substring/solutions/2448334/easy-c-solution-simple-to-understand/

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