class Solution {

	void dfs(std::unordered_map<int, std::vector<int>>& map, int v)
	{
		auto& r = map[v];

		// v n

		for (int n : r)
		{

		}
	}


public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		std::unordered_map<int, std::vector<int>> map;

		for (const auto& r : roads)
		{
			map[r[0]].push_back(r[1]);
			map[r[1]].push_back(r[0]);
		}

		for (const auto& road : roads)
		{
			std::unordered_map<int, int> m;

			// 0 , 1
			for (int v : road)
			{

			}
		}
	}
};