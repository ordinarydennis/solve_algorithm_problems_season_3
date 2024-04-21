class MyQueue {
public:
	MyQueue() {

	}

	void push(int x) {

		st1.push(x);

	}

	int pop() {

		if (st2.empty())
			transfer();

		int n = st2.top();

		st2.pop();

		return n;

	}

	int peek() {

		if (st2.empty())
			transfer();

		return st2.top();
	}

	bool empty() {

		return st1.empty() && st2.empty();

	}


private:
	void transfer()
	{
		while (st1.size())
		{
			st2.push(st1.top());
			st1.pop();
		}
	}

private:
	std::stack<int> st1;
	std::stack<int> st2;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */







class MyQueue {
public:
	MyQueue() {

	}

	void push(int x) {

		s1.push(x);

	}

	int pop() {

		transfer();

		int n = s2.top();
		s2.pop();
		return n;
	}

	int peek() {

		transfer();

		int n = s2.top();

		return n;
	}

	bool empty() {

		return s2.empty() && s1.empty();

	}


private:
	void transfer()
	{
		if (s2.empty())
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
	}

private:
	std::stack<int> s1;
	std::stack<int> s2;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */