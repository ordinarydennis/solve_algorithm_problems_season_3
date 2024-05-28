class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		unordered_map<int, unordered_set<int>> map;

		for (const auto& r : roads)
		{
			map[r[0]].insert(r[1]);
			map[r[1]].insert(r[0]);
		}

		int ret = 0;

		for (int s = 0; s < n; s++)
		{
			for (int e = s + 1 ; e < n; e++)
			{
				int level = map[s].size() + map[e].size();

				if (map[s].count(e))
				{
					level--;
				}
				ret = std::max(ret, level);
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		int maxRank = 0;
		unordered_map<int, unordered_set<int>> adj;
		// Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
		for (auto& road : roads) {
			adj[road[0]].insert(road[1]);
			adj[road[1]].insert(road[0]);
		}

		// Iterate on each possible pair of nodes.
		for (int node1 = 0; node1 < n; ++node1) {
			for (int node2 = node1 + 1; node2 < n; ++node2) {
				int currentRank = adj[node1].size() + adj[node2].size();
				if (adj[node1].find(node2) != adj[node1].end()) {
					--currentRank;
				}
				// Find the current pair's respective network rank and store if it's maximum till now.
				maxRank = max(maxRank, currentRank);
			}
		}
		// Return the maximum network rank.
		return maxRank;
	}
};

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
			for (int c2 = c1 + 1; c2 < n; c2++)
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