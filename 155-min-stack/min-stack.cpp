class MinStack {
    stack<int>st;
    stack<int>mn;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(mn.empty() || mn.top()>value) mn.push(value);
        else mn.push(mn.top());
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        int a=st.top();
        return a;
    }
    
    int getMin() {
        int a=mn.top();
        return a;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */