class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {

		int min = 0;
		int max = 0;

		std::sort(points.begin(), points.end(), [&min, &max](vector<int>& p1, vector<int>& p2) {

			min = std::min(min, std::min(p1[0], p2[0]));
			max = std::max(max, std::max(p1[1], p2[1]));

			if (p1[0] > p2[0])
			{
				return false;
			}

			if (p1[1] > p2[1])
			{
				return false;
			}

			return true;

			}
		);


		bool isShoot = false;

		int ret = INT_MAX;

		for (int i = min; i <= max; i++)
		{
			int count = 0;

			for (const auto& p : points)
			{
				if (false == isShoot && p[0] <= i && i <= p[1])
				{
					count++;
					isShoot = true;
				}
				else
				{
					isShoot = false;
				}
			}

			ret = std::min(ret, count);
		}

		return ret;
	}
};