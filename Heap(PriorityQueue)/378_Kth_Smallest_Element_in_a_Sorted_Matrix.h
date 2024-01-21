class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {

		std::multimap<int, pair<int, int>> m;

		std::set<pair<int, int>> s;

		int maxY = matrix.size();
		int maxX = matrix[0].size();

		m.insert({ matrix[0][0] , pair<int,int>{0,0} });
		
		int count = 0;

		while (m.size())
		{
			auto it = m.begin();

			count++;
			
			if (count == k)
			{
				return it->first;
			}

			if (it->second.first + 1 < maxY)
			{
				if (!s.count(pair{ it->second.first + 1, it->second.second }))
				{
					m.emplace(
						matrix[it->second.first + 1][it->second.second],
						pair<int, int> {
						it->second.first + 1,
							it->second.second
					}
					);

					s.insert(pair<int, int> {
						it->second.first + 1,
							it->second.second
					});
				}
			}

			if (it->second.second + 1 < maxX)
			{
				if (!s.count(pair{ it->second.first, it->second.second + 1}))
				{
					m.emplace(
						matrix[it->second.first][it->second.second + 1],
						pair<int, int> {
						it->second.first,
							it->second.second + 1
					}
					);
					s.insert(pair<int, int> {
						it->second.first,
						it->second.second + 1
					});
				}

			}

			m.erase(it);

		}

		return 0;
	}
};