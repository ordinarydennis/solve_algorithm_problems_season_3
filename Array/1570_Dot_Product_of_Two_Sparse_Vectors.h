class SparseVector {
public:

	SparseVector(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i]) continue;

			mNums[i] = nums[i];
		}
		 
	}

	// Return the dotProduct of two sparse vectors
	int dotProduct(SparseVector& vec) {

		int sum = 0;

		//for (int i = 0; i < mNums.size(); i++)
		//{
		//	sum += mNums[i] * vec.mNums[i];
		//}

		for (const auto& [i, n] : mNums)
		{
			sum += vec.mNums[i] * n;
		}

		return sum;
	}


private:
	//vector<int> mNums;
	unordered_map<int, int> mNums;



};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);