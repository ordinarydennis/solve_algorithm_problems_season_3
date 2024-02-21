
class Solution {
public:
	string convertToTitle(int columnNumber) {

		string ret;

		while (columnNumber)
		{
			columnNumber--;

			int n = (columnNumber %  26);

			char c = n + 'A';
			
			ret = c + ret;

			columnNumber = columnNumber / 26;
		}

		return ret;

	}
};

//https://leetcode.com/problems/excel-sheet-column-title/solutions/3943071/100-recursive-iterative-2-approaches/



