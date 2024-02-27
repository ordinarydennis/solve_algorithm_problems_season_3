class Solution {
public:
	Solution(vector<int>& nums)
	: mOrigin(nums)
	{

	}

	vector<int> reset() {

		return mOrigin;

	}

	vector<int> shuffle() {

		auto nums = mOrigin;

		for (int i = 0; i < nums.size(); i++)
			swap(nums[i], nums[rand() % nums.size()]);

		return nums;
	}

private:
	vector<int> mOrigin;


};

class Solution {
	vector<int> original;
	int n;
public:

	Solution(vector<int>& nums) {
		original = nums;
		n = original.size();
	}

	vector<int> reset() {
		return original;
	}

	vector<int> shuffle() {
		//make a copy of the original
		vector<int> shuffled = original;

		int leftSize = n;
		for (int i = n - 1; i >= 0; i--) {
			//draw from the bag
			int j = rand() % leftSize;

			//put this element at current position
			//and put the original element in the bag
			swap(shuffled[i], shuffled[j]);
			leftSize--;
		}
		return shuffled;
	}

};

//https://leetcode.com/problems/shuffle-an-array/solutions/1283088/c-solution-with-intuition-and-explanation/
