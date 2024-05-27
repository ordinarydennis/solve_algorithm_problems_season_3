class Solution {

	int GetLevel(int a, int b, unordered_map<int, vector<int>>& networks)
	{
		set<std::pair<int, int>> linkSet;

		int level = 0;

		for (const auto c : networks[a])
		{
			linkSet.insert(std::pair<int, int> {a, c});
			linkSet.insert(std::pair<int, int> {c, a});
			level++;
		}
		

		for (const auto c : networks[b])
		{
			if (linkSet.count({ c, b }) || linkSet.count({ b, c }))
			{
				continue;
			}

			linkSet.insert(std::pair<int, int> {c, b});
			linkSet.insert(std::pair<int, int> {b, c});

			level++;
		}

		return level;
	}


public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		unordered_map<int, vector<int>> networks;

		for (const auto& cities : roads)
		{
			networks[cities[0]].push_back(cities[1]);
			networks[cities[1]].push_back(cities[0]);
		}

		int ret = 0;

		for (const auto&  [c1, ne] : networks)
		{
			for (int c2 : ne)
			{
				ret = max(ret, GetLevel(c1, c2, networks));
			}
		}

		return ret;
	}
};

class Solution {

	int GetLevel(int a, int b, unordered_map<int, vector<int>> networks)
	{
		set<std::pair<int, int>> linkSet;

		int level = 0;

		for (const auto c : networks[a])
		{
			linkSet.insert(std::pair<int, int> {a, c});
			linkSet.insert(std::pair<int, int> {c, a});
			level++;
		}


		for (const auto c : networks[b])
		{
			if (linkSet.count({ c, b }) || linkSet.count({ b, c }))
			{
				continue;
			}

			linkSet.insert(std::pair<int, int> {c, b});
			linkSet.insert(std::pair<int, int> {b, c});

			level++;
		}

		return level;
	}


public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		unordered_map<int, vector<int>> networks;

		for (const auto& cities : roads)
		{
			networks[cities[0]].push_back(cities[1]);
			networks[cities[1]].push_back(cities[0]);
		}

		int ret = 0;

		for (int c1 = 0; c1 < n - 1; c1++)
		{
			for (int c2 = 0; c2 < n; c2++)
			{
				ret = max(ret, GetLevel(c1, c2, networks));
			}
		}

		return ret;
	}
};


0 : 1
1 : 0, 2
2 : 1, 3, 4
3 : 2
4 : 2, 
5 : 6, 7
6 : 5
7 : 5



n =
8
roads =
[[0, 1], [1, 2], [2, 3], [2, 4], [5, 6], [5, 7]]
Output
4
Expected
5