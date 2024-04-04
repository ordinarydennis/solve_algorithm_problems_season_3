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
			list.push_back(getMin(time));

		std::sort(list.begin(), list.end());

		int min = INT_MAX;

		for (int i = 1; i < list.size(); i++)
			min = std::min(min, list[i] - list[i - 1]);

		//because time is circulates, need to subtract between last to begin time to find minimum time gap.
		return std::min(min, (1440 + list[0]) - list[list.size() - 1]);
	}
};

//https://leetcode.com/problems/minimum-time-difference/solutions/4030795/c-o-nlogn-explained-easiest-approach-so-far/

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int>temp;

		//CONVERSION TO MINUTES:-  TC= o(n)

		for (int i = 0;i < timePoints.size();i++)
		{
			string s = timePoints[i];
			int hour = stoi(s.substr(0, 2));
			int minute = stoi(s.substr(3, 2));
			int total = hour * 60 + minute;
			temp.push_back(total);
		}


		//SORT THE VECTOR OF MINUTES:- TC = O(nlogn)

		sort(temp.begin(), temp.end());


		//CALCULATE THE  MIN. DIFFERENCE:-  TC = O(n)

		int mini = INT_MAX;
		int n = temp.size();
		for (int i = 0;i < n - 1;i++)
		{
			int difference = temp[i + 1] - temp[i];
			mini = min(difference, mini);

		}

		int last = (temp[0] + 1440) - temp[n - 1]; // 24hours *60 min. = 1440 min.
		mini = min(last, mini);

		return mini;
	}
};