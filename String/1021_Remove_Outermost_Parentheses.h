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

class Solution {
public:
	string removeOuterParentheses(string S) {
		string res;
		int opened = 0;
		for (char c : S) {
			if (c == '(' && opened++ > 0) res += c;
			if (c == ')' && opened-- > 1) res += c;
		}
		return res;
	}

};

//https://leetcode.com/problems/remove-outermost-parentheses/solutions/270022/java-c-python-count-opened-parenthesis/

