class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {

		std::sort(g.begin(), g.end(), std::greater<int>());
		std::sort(s.begin(), s.end(), std::greater<int>());

		int ret = 0;

		int i = 0;
		int j = 0;

		while (j < static_cast<int>(g.size()) && i < static_cast<int>(s.size()))
		{
			if (s[i] >= g[j])
				i++, ret++;

			j++;
		}

		return ret;
	}
};

//https://leetcode.com/problems/assign-cookies/solutions/4485308/o-n-log-n-time-o-1-space-c-java-python-js-explained-sorting/