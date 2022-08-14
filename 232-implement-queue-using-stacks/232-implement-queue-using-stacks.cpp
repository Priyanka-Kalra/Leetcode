class MyQueue {
    stack<int> S;
public:
    
    void push(int x) {
        S.push(x);
    }
    
    int pop() {
        stack<int> t;
        while(!S.empty()){
            t.push(S.top());
            S.pop();
        }
        int val=t.top();
        t.pop();
        while(!t.empty()){
            S.push(t.top());
            t.pop();
        }
        return val;
    }
    
    int peek() {
        
        stack<int> t;
        while(!S.empty()){
            t.push(S.top());
            S.pop();
        }
        int val=t.top();
        while(!t.empty()){
            S.push(t.top());
            t.pop();
        }
        return val;
        
    }
    
    bool empty() {
        return S.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */