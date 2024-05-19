class Solution {
public:
	string minRemoveToMakeValid(string s) {

		std::stack<int> st;

		std::set<int> vs;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else if(s[i] == ')')
			{
				if (st.size())
				{
					vs.insert(st.top());
					vs.insert(i);
					st.pop();
				}
			}
		}

		string ret(s.size());

		for (int i = 0; i < s.size(); i++)
		{
			if (vs.count(i))
			{
				ret[i] = s[i];
			}
			else if ('(' != s[i] && ')' != s[i])
			{
				ret.push_back(s[i]);
			}
		}

		return ret;
	}
};