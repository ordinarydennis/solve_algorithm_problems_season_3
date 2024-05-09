class Solution {
public:
	std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
		int n = temperatures.size();
		std::vector<int> answer(n, 0);  // Initialize all to 0
		std::stack<int> stack;

		for (int currDay = 0; currDay < n; currDay++) {
			int currentTemp = temperatures[currDay];
			// Pop until the current day's temperature is not
			// warmer than the temperature at the top of the stack
			while (!stack.empty() && temperatures[stack.top()] < currentTemp) {
				int prevDay = stack.top();
				stack.pop();
				answer[prevDay] = currDay - prevDay;
			}
			stack.push(currDay);
		}

		return answer;
	}
};



class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {

		vector<int> ret(temperatures.size());

		for (int s = 0; s < temperatures.size() - 1; s++)
		{
			for (int e = s + 1; e < temperatures.size(); e++)
			{
				if (temperatures[s] < temperatures[e])
				{
					ret[s] = e - s;
					break;
				}
			}
			
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {

		vector<int> ret(temperatures.size());

		std::map<int, int> m;

		for (int i = 0; i < temperatures.size(); i++)
		{
			m[temperatures[i]] = i;
		}


		for (int i = 0; i < temperatures.size(); i++)
		{
			auto it = m.find(temperatures[i]);

			it++;

			while (it != m.end())
			{
				if (i < it->second)
				{
					ret[i] = it->second - i;
					break;
				}
				else
				{
					it++;
				}
			}
		}

		return ret;
	}
};