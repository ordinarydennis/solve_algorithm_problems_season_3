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


class KthLargest {

public:
	KthLargest(int k, vector<int>& nums) {

		m_k = k;
		for (int x : nums)
			add(x);
	}

	int add(int val) {
		//the queue maintains only m_k values 
		//so that the top element is kth largest element.
		if (minheap.size() < m_k)
			minheap.push(val);
		else
		{
			//if the value added is bigger than top element,
			//pop the top element and add val value.
			if (val > minheap.top())
			{
				minheap.pop();
				minheap.push(val);
			}
		}
		return minheap.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> minheap;
	int m_k;

};

//https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/596093/c-solution-with-understandable-explaination/
