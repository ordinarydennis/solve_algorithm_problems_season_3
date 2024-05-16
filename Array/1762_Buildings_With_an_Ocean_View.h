class Solution {
public:
	vector<int> findBuildings(vector<int>& heights) {

		vector<int> ret;

		vector<int> max(heights.size());

		ret.push_back(heights.size() - 1);

		max[heights.size() - 1] = heights.back();
	
		for (int i = heights.size() - 2; 0 <= i; i--)
		{
			if (max[i + 1] < heights[i])
			{
				ret.push_back(i);
			}

			max[i] = std::max(max[i + 1], heights[i]);
		}

		sort(ret.begin(), ret.end());

		return ret;

	}
};