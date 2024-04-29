class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {

		std::sort(intervals.begin(), intervals.end());

		int end = intervals[0][1];

		int ret = 1;

		for (int i = 1; i < intervals.size(); i++)
		{
			int s = intervals[i][0];
			int e = intervals[i][1];

			if (s < end)
			{
				ret++;
				end = std::min(end, e);
			}
			else
			{
				end = e;
			}
			
		}

		return ret;

	}
};
