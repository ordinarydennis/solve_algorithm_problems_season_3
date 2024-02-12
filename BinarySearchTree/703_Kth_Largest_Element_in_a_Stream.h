class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {

		mK = k;

		for (int n : nums)
			mMs.insert(n);

	}

	int add(int val) {

		mMs.insert(val);

		auto it = mMs.begin();

		std::advance(it, (mK - 1));

		return *it;
	}

private:
	multiset<int, greater<int>>		mMs;
	int								mK = 0;

};
