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


class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i & (i - 1)] + 1;
		return ret;
	}
};
//https://leetcode.com/problems/counting-bits/solutions/79527/four-lines-c-time-o-n-space-o-n/

//& operation between current and previous;
//why do I operate & between current and previous;
//When the number is 2 to the power of n, & operate between number and numner -1 means that zero.
//see the example below
//0111 7
//1000 8
//the meaning of & operation between current and previous number is index of 2 to power of n or previous number
//the result of & operation is used by index of array

0000 0
0001 1
0010 2
0011 3
0100 4
0101 5
0110 6
0111 7
1000 8
1001 9
1010 10
