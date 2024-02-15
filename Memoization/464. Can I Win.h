class Solution {

	bool dfs(vector<bool>& use, int total, bool first)
	{
		if(total <= 0)
		{
			return first;
		}

		for(int i = use.size() - 1;  0 <= i; i--)
		{
			if(use[i])
				continue;

			use[i] = true;

			if(dfs(use, total - i, !first))
				return true;

			use[i] = false;
		}

		return false;
	}



public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {

			vector<bool> use(static_cast<int>(maxChoosableInteger + 1));

			return dfs(use, desiredTotal, true);
	}
};