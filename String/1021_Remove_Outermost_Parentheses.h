class Solution {
public:
	string removeOuterParentheses(string s) {

		int open = 0;
		int start = 0;

		string ret;

		for (int i = 0; i < static_cast<int>(s.size()); i++)
		{
			if ('(' == s[i])
			{
				if (1 == ++open) 
					start = i;
			}
			else
			{
				if (0 == --open && i - start != 1)
					ret += s.substr(start + 1, i - start - 1);
			}
		}

		return ret;
	}
};