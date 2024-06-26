class MyStack {
public:
	MyStack() {

	}

	void push(int x) {

		int size = static_cast<int>(q.size());

		q.push(x);

		for (int i = 0; i < size; i++)
		{
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {

		int n = q.front();
		q.pop();
		return n;

	}

	int top() {

		return q.front();

	}

	bool empty() {

		return q.empty();
	}


private:
	std::queue<int> q;


};

class MyStack {
public:
	MyStack() {

	}

	void push(int x) {

		q1.push(x);

		while (q2.size())
		{
			q1.push(q2.front());
			q2.pop();
		}

		swap(q1, q2);
	}

	int pop() {

		int n = q2.front();
		p2.pop();
		return n;

	}

	int top() {

		return q2.front();

	}

	bool empty() {

		return q2.empty();
	}


private:
	std::queue<int> q1;
	std::queue<int> q2;


};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */






class MyStack {
public:
	MyStack() {

	}

	void push(int x) {

		(isfq) ? fq.push(x) : sq.push(x);

	}

	int pop() {

		int ret = 0;

		transfer();

		if (isfq)
		{
			ret = fq.front();
			fq.pop();
		}
		else
		{
			ret = sq.front();
			sq.pop();
		}

		isfq = !isfq;

		return ret;
	}

	int top() {

		int ret = 0;

		transfer();

		if (isfq)
		{
			ret = fq.front();
			fq.pop();
			sq.push(ret);
		}
		else
		{
			ret = sq.front();
			sq.pop();
			fq.push(ret);
		}

		isfq = !isfq;

		return ret;
	}

	bool empty() {

		return fq.empty() && sq.empty();

	}


private:
	void transfer()
	{
		if (isfq)
		{
			auto size = fq.size() - 1;
			for (int i = 0; i < size; i++)
			{
				int n = fq.front();
				fq.pop();
				sq.push(n);
			}
		}
		else
		{
			auto size = sq.size() - 1;
			for (int i = 0; i < size; i++)
			{
				int n = sq.front();
				sq.pop();
				fq.push(n);
			}
		}
	}


private:
	std::queue<int> fq;
	std::queue<int> sq;
	bool isfq = true;

};

//using two queues
class MyStack {
public:
	MyStack() {

	}

	void push(int x) {

		q2.push(x);

		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}

		swap(q2, q1);
	}

	int pop() {

		int n = top();

		q1.pop();

		return n;

	}

	int top() {

		return q1.front();
	}

	bool empty() {

		return q1.empty();

	}


private:
	std::queue<int> q1;
	std::queue<int> q2;


};

//using one queue
class MyStack {
public:
	MyStack() {

	}

	void push(int x) {

		q.push(x);

		for (int i = 0; i < q.size() - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {

		int n = top();

		q.pop();

		return n;

	}

	int top() {

		return q.front();

	}

	bool empty() {

		return q.empty();

	}


private:
	std::queue<int> q;

};

https://leetcode.com/problems/implement-stack-using-queues/solutions/765739/c-100-00-2-queues-100-00-1-queue-easy-to-understand/


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */