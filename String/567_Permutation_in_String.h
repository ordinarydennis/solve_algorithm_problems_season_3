class Solution {

	bool isContain(string& s1, string& s2, string& p, std::unordered_set<int>& visitSet)
	{
		if (p.size() == s1.size())
		{
			return s2.find(p) != string::npos;
		}
		
		bool ret = false;

		for (int i = 0; i < s1.size(); i++)
		{
			if (visitSet.count(i))
				continue;

			visitSet.insert(i);

			p.push_back(s1[i]);

			if (isContain(s1, s2, p, visitSet))
			{
				ret = true;
				break;
			}

			p.pop_back();

			visitSet.erase(i);
			
		}

		return ret;
	}


public:
	bool checkInclusion(string s1, string s2) {

		std::unordered_set<int> visitSet;

		std::unordered_map<char, int> s1Map;
		std::unordered_map<char, int> s2Map;

		for (auto c : s1)
		{
			s1Map[c]++;
		}

		for (auto c : s2)
		{
			s2Map[c]++;
		}

		if (s2Map.size() < s1Map.size())
		{
			return false;
		}

		for (auto& [c, num] : s1Map)
		{
			auto it = s2Map.find(c);
			if (it == s2Map.end())
			{
				return false;
			}

			if (it->second < num)
			{
				return false;
			}
		}

		string p;

		return isContain(s1, s2, p, visitSet);
	}
};

https://leetcode.com/problems/permutation-in-string/solutions/357821/c-concise-solution/
bool checkInclusion(string s1, string s2) {
	vector<int> cur(26), goal(26);
	
	for (char c : s1) 
		goal[c - 'a']++;

	for (int i = 0; i < s2.size(); i++) {
		
		cur[s2[i] - 'a']++;

		if (i >= s1.size()) 
			cur[s2[i - s1.size()] - 'a']--;
		
		if (goal == cur) 
			return true;
	}
	return false;
}



https://leetcode.com/problems/permutation-in-string/editorial/
