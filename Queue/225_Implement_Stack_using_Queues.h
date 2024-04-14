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
https://leetcode.com/problems/implement-stack-using-queues/solutions/765739/c-100-00-2-queues-100-00-1-queue-easy-to-understand/

//using one queue

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {

        q.push(x);

        for (int i = 0; i < q.size() - 1; i++)
        {

        }
    }

    int pop() {

    }

    int top() {

    }

    bool empty() {

    }


private:
    std::queue<int> q;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */