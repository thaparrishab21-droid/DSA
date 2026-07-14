class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        while(!q1.empty()){
            int a=q1.front();
            q2.push(a);
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            int a= q2.front();
            q1.push(a);
            q2.pop();
        }
    }
    
    int pop() {
        int p=q1.front();
        q1.pop();
        return p;
    }
    
    int top() {
        int p=q1.front();
        return p;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */