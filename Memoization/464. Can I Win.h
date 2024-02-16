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


class Solution {

	// DFS to check if I can win
	// k: current game state
	// T: remaining total to reach
	bool dfs(int M, int T, int k) 
	{
		// memorized
		if (mem[k] != 0) return mem[k] > 0;
		
		// total is already reached by opponent, so I lose
		if (T <= 0) return false;

		// try all currently available numbers
		for (int i = 0; i < M; ++i)
		// if (i+1) is available to pick and my opponent can't win after I picked, I win!
		if (!(k&(1<<i)) && !dfs(M, T-i-1, k|(1<<i))) {
			mem[k] = 1;
			return true;
		} 
		
		// Otherwise, I will lose
		mem[k] = -1;
		return false;      
	}

public:
	bool canIWin(int M, int T) 
	{
		int sum = M*(M+1)/2; // sum of entire choosable pool

		// I just pick 1 to win
		if (T < 2) return true;
		
		// Total is too large, nobody can win
		else if (sum < T) return false;
		
		// Total happens to match sum, whoever picks at odd times wins
		else if (sum == T) return M%2;
		
		// Non-trivial case: do DFS
		// Initial total: T
		// Initial game state: k = 0 (all numbers are not picked)
		else return dfs(M, T, 0);
	}

	// m[key]: memorized game result when pool state = key
	// 0: un-computed; 1: I win; -1: I lose
	int mem[1<<20] = {};
};


//https://leetcode.com/problems/can-i-win/solutions/95320/clean-c-beat-98-4-dfs-with-early-termination-check-detailed-explanation/
