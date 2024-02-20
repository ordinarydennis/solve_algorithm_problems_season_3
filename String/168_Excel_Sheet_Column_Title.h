
class Solution {
public:
	string convertToTitle(int columnNumber) {

		string ret;

		while (columnNumber)
		{
			int n = (columnNumber %  27);

			char c = n + ('A' - 1);
			
			ret = ret + c; 

			columnNumber = columnNumber / 27;
		}

		return ret;

	}
};
