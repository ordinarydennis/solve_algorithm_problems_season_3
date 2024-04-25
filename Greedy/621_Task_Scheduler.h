class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {

		//char, count, next index
		std::map<char, pair<int, int>> mm;


		for (char c : tasks)
		{
			mm[c].first++;
		}

		int interval = 0;

		for (auto& [c, p] : mm)
		{
			p.second = interval;
			interval++;
		}

		int ret = 0;
		
		interval = 0;

		while (mm.size())
		{
			for (auto it = mm.begin(); it != mm.end(); )
			{
				auto p = it->second;

				if (p.second == interval)
				{
					p.first--;

					if (0 == p.first)
					{
						it = mm.erase(it);
						continue;
					}

					p.second += n + 1;
				}

				interval++;
				++it;
			}
		}

		return interval;
	}
};