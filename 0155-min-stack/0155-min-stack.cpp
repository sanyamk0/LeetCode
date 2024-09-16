class MinStack {
public:
    stack<pair<int, long long>> st;
    long long mini = LONG_MAX;
    MinStack() {}

    void push(int val) {
        mini = min(mini, (long long)val);
        st.push({val, mini});
    }

    void pop() {
        st.pop();
        if (!st.empty()) {
            mini = st.top().second;
        } else {
            mini = LONG_MAX;
        }
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */