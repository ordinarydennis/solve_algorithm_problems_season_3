class Solution {

	void recursion(set<int>& s, bool left)
	{
		if(1 == static_cast<int>(s.size()))
		{
			return;
		}
		
		auto it = (left) ? s.begin() : s.end();

		if(false == left)
		{
			--it;
		}

		int size = static_cast<int>(s.size() / 2);


		if(size % 2 != 0)
		{
			size++;
		}

		for(int c = 0; c < size; c++)
		{
			it = s.erase(it);

			if(left)
			{
				++it;
			}
			else
			{
				--it;
				--it;
			}
		}

		recursion(s, !left);
	}

public:
	int lastRemaining(int n) {

		set<int> s;

		for (int i = 1; i <= n; i++)
		{
			s.insert(i);
		}

		recursion(s, true);

		return *s.begin();
	}

};


class Solution {
public:
	int lastRemaining(int n) {
		if (n == 1) {
			return 1;
		}
		return 2 * (n / 2 + 1 - lastRemaining(n / 2));
	}
};

//https://leetcode.com/problems/elimination-game/solutions/4277182/mathematical-approach-recursion-o-log-n/