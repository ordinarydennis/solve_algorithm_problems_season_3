class Solution {

	int GetmanhattanDistance(const vector<int>& a, const vector<int>& b)
	{
		return abs(b[0] - a[0]) + abs(b[1] - a[1]);
	}

public:
	int minCostConnectPoints(vector<vector<int>>& points) {

		std::unordered_map<int, pair<int, int>> m;

		for (int a = 0; a < points.size() - 1; a++)
		{
			for (int b = a + 1; b < points.size(); b++)
			{
				int d = GetmanhattanDistance(points[a], points[b]);
				
				auto it = m.find(b);

				if (m.end()  == it)
				{
					m.emplace(b, pair<int, int>{ a, d });
				}
				else
				{
					auto be = m.begin();

					if (d < be->second.second)
					{
						it->second.first = a;
						it->second.second = d;
					}
				}
			}
		}

		int ret = 0;

		for (auto [_, p] : m)
		{
			ret += p.second;
		}

		return ret;

	}
};