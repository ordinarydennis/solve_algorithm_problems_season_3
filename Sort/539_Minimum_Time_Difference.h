class Solution {

	int getMin(string& time)
	{
		int h1 = time[0] - '0';
		int h2 = time[1] - '0';

		int m1 = time[time.size() - 2] - '0';
		int m2 = time[time.size() - 1] - '0';

		return ((h1 * 10) + h2) * 60 + (m1 * 10 + m2);
	}

public:
	int findMinDifference(vector<string>& timePoints) {

		std::vector<int> list;

		for (auto& time : timePoints)
		{
			list.push_back(getMin(time));
		}

		std::sort(list.begin(), list.end());

		int min = INT_MAX;

		bool is0 = (0 == *list.begin());

		for (int i = 1; i < list.size(); i++)
		{
			int a = list[i - 1];
			int b = list[i];

			if (0 == a)
			{
				min = std::min(min,
					std::min(1440 - b, b - a)
				);
			}
			else
			{
				min = std::min(min, b - a);
			}

			if (is0)
			{
				min = std::min(min, 1440 - b);
			}
		}

		return min;
	}
};