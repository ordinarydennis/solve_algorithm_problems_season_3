class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {

		int pre = arr[0];

		int count = 1;

		for (int i = 1; i <= arr.size(); i++)
		{
	  
			if (i < arr.size() && pre == arr[i])
			{
				count++;
			}
			else
			{
				if ((arr.size() * 100 / 4) < count * 100)
				{
					return arr[i - 1];
				}
				count = 1;
				pre = arr[i];
			}
		}

		return 0;
	}
};