class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {

		std::unordered_map<char, string> m;

		for (const auto& str : dictionary)
		{
			auto it = m.find(str[0]);
			if (m.end() == it)
			{
				m.emplace(str[0], str);
			}
			else if(str.size() < it->second.size())
			{
				it->second = str;
			}
		}

		string str;

		string ret;

		for (int i = 0; i <= sentence.size(); i++)
		{
			if (i == sentence.size() || ' ' == sentence[i])
			{
				auto it = m.find(str[0]);

				if (m.end() == it)
				{
					ret += str;
				}
				else
				{
					auto sub = str.substr(0, it->second.size());
					if (sub == it->second)
					{
						ret += it->second;
					}
					else
					{
						ret += str;
					}
				}

				if (i < sentence.size())
				{
					ret += sentence[i];

				}

				str.clear();
			}
			else
			{
				str += sentence[i];
			}

		}

		return ret;
	}
};