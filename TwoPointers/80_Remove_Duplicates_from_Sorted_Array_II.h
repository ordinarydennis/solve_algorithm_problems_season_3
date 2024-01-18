class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if(nums.size() == 1)
		{
			return 1; 
		}

		int initNumsSize = nums.size();
		int pre = nums[0];
		int count = 1;
		int eraseCount = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (pre == nums[i])
			{
				if(2 == count)
				{
					nums.erase(nums.begin() + i);
					eraseCount++ ;
					i--;
				}
				else
				{
					count++;
				}
			}
			else
			{
				pre = nums[i];
				count = 1;
			}
		}

		return initNumsSize - eraseCount;

	}
};