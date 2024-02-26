class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {

		map<int, int> remainMap;

		for (int pay : bills)
		{
			int change = pay - 5;

			for (auto& [e, amount] : remainMap)
			{
				if (amount - change < 0)
				{
					continue;
				}

				amount -= change;
				change -= change;
				break;
			}

			if (0 < change)
			{
				return false;
			}

			remainMap[pay] += 5;
		}

		return true;
	}
};

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {

		int five = 0;
		int ten = 0;

		for (int bill : bills)
		{
			if (5 == bill)
			{
				five++;
			}
			else if (10 == bill)
			{
				if (0 == five)
					return false;

				five--;
				ten++;
			}
			else
			{
				if (five && ten)
					five--, ten--;
				else if (3 <= five)
					five -= 3;
				else
					return false;
			}
		}

		return true;
	}
};

//https://leetcode.com/problems/lemonade-change/solutions/3451775/c-java-python-fully-explained-greedy-algo/

