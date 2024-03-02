class NumArray {
public:
    NumArray(vector<int>& nums)
        :mNums(std::move(nums))
    {

    }

    int sumRange(int left, int right) {

        return std::accumulate(mNums.begin() + left, mNums.begin() + right + 1, 0);

    }

private:
    vector<int> mNums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */