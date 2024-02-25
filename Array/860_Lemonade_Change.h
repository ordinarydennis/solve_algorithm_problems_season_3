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