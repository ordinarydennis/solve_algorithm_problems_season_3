class Solution {
public:
	int tribonacci(int n) {

		int tarr[3] = { 0, 1, 1 };

		if (n < 3)
			return tarr[n];

		n -= 2;

		while (n--)
		{
			int temp = tarr[2];
			tarr[2] = tarr[0] + tarr[1] + tarr[2];
			tarr[0] = tarr[1];
			tarr[1] = temp;
		}

		return tarr[2];
	}
};