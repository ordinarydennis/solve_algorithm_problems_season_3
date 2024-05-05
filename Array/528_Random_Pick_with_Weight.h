class Solution {
public:
	Solution(vector<int>& w) {
		
		int sum = 0;

		for (int n : w)
		{
			sum += n;
			mSum.push_back(sum);
		}
	}

	int pickIndex() {

		float r = (float)(rand()) / RAND_MAX;

		float t = r * mSum.back();

		for (int i = 0; i < mSum.size(); i++)
		{
			if (t < mSum[i])
			{
				return i;
			}
		}

		return mSum.size() - 1;
	}

private:
	vector<int> mSum;

};

class Solution {
public:
	Solution(vector<int>& w) {

		mW = std::move(w);

		mSum = std::accumulate(mW.begin(), mW.end(), 0);
	}

	int pickIndex() {

		int sum = 0;

		int t = rand() % mSum;

		for (int i = 0; i < mW.size(); i++)
		{
			sum += mW[i];
			if (t < sum)
			{
				return i;
			}
		}

		return mW.size() - 1;
	}


private:
	vector<int> mW;
	int mSum = 0;

};