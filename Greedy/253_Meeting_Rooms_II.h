class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {

		vector<int> sList(intervals.size());
		vector<int> eList(intervals.size());

		std::sort(intervals.begin(), intervals.end());

		for (int i = 0; i < intervals.size(); i++)
		{
			sList[i] = intervals[i][0];
			eList[i] = intervals[i][1];
		}

		std::sort(sList.begin(), sList.end());
		std::sort(eList.begin(), eList.end());

		int ret = 0;

		int eI = 0;
		for (int i = 0; i < sList.size(); i++)
		{
			if (sList[i] < eList[eI])
			{
				ret++;
			}
			else
			{
				eI++;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {

		std::priority_queue<int, vector<int>, greater<int>> endQ;

		std::sort(intervals.begin(), intervals.end());

		endQ.push(intervals[0][1]);

		for (int i = 1; i < intervals.size(); i++)
		{
			if (endQ.top() <= intervals[i][0])
			{
				endQ.pop();
			}

			endQ.push(intervals[i][1]);
		}

		return endQ.size();
	}
};



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
