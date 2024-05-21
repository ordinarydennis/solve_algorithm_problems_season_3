class Solution {

	inline static vector<pair<int, int>> dir = {
		{-2, 1},
		{-2, -1},
		{-1, 2},
		{-1, -2},
		{2, 1},
		{2, -1},
		{1, 2},
		{1, -2},
	};

	map<tuple<int, int, int>, int> memo;

private:
	int dfs(vector<vector<int>>& pad, int x, int y, vector<bool>& v, int n, int c)
	{
		tuple<int, int, int> t = { x, y, c };
		
		if (memo.count(t))
		{
			return memo[t];
		}

		if (n == c)
		{
			return 1;
		}
		
		int ret = 0;

		for (const auto& [yd, xd] : dir)
		{
			int cy = y + yd;
			int cx = x + xd;

			if (cy < 0 || cx < 0)
			{
				continue;
			}
			if (3 < cy || 2 < cx)
			{
				continue;
			}

			if (-1 == pad[cy][cx])
			{
				continue;
			}

			if (v[pad[cy][cx]])
			{
				continue;
			}
		
			//v[pad[cy][cx]] = true;

			int n = dfs(pad, xd, yd, v, n, c + 1);
			
			tuple<int, int, int> t = { xd, yd, c + 1};

			memo[t] = n;

			ret += n;

			//v[pad[cy][cx]] = false;
		}

		return ret;
	}


public:
	int knightDialer(int n) {

		vector<vector<int>> pad = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{-1, 0, -1}
		};

		vector<bool> v(9);

		int ret = 0;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (-1 == pad[y][x])
				{
					continue;
				}

				ret += dfs(pad, x, y, v, n, 1);
			}
		}

		return ret;
	}
};