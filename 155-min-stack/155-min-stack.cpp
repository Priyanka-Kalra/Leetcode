class MinStack {
    stack<int> s;
    stack<int> minS;
    
    
public:
    MinStack() {
        minS.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        int temp=min(val,minS.top());
        minS.push(temp);
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */