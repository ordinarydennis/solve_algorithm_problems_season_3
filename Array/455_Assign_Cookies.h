class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {


		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end());

		int ret = 0;

		int i = 0;
		int j = 0;

		for (; i < static_cast<int>(s.size()); )
		{
			if (static_cast<int>(g.size()) <= j)
				break;

			if (static_cast<int>(g.size()) <= i)
				break;

			if (s[i] >= g[j])
			{
				j++;
				ret++;
				s[i]--;
			}
			i++;
		}

		return ret;
	}
};