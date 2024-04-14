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