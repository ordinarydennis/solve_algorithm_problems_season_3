
class Solution {
public:
	string findLongestWord(string s, vector<string>& dictionary) {

		string ret;

		int slen = s.size();
		
		for (auto dicStr : dictionary)
		{
			int dlen = dicStr.size();

			int a = 0;
			int b = 0;

			while (a < slen && b < dlen)
			{
				if (s[a] == dicStr[b])
					b++;
				a++;
			}

			if (dlen <= b)
			{
				if (ret.size() < dicStr.size())
				{
					ret = dicStr;
				}
				else if (ret.size() == dicStr.size() && dicStr < ret)
				{
					ret = dicStr;
				}
			}
		}

		return ret;
	}
};