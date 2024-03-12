class Solution {
public:
	vector<int> countBits(int n) {

		vector<int> ret(n + 1);

		int lastNum = 0;

		int bi = 2;

		for (int i = 1; i <= n; i++)
		{
			if (i == bi)
			{
				ret[i] = 1;
				lastNum = i;
				bi <<= 1;
			}
			else
			{
				ret[i] = ret[i - lastNum] + 1;
			}
		}

		return ret;
	}
};
