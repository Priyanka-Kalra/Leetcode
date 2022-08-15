//https://www.youtube.com/watch?v=3Et9MrMc02A&t=249s
//1.using two stacks s1,s2(pop element one by one from s1 and push in s2.after this insert element (to be inserted) in s1.pop element one by one from s2 and push in s1.)TC-O(N) for push and TC-O(1)for rest


class MyQueue {
    stack<int> s1;
public:
    void push(int x) {
        stack<int> s2;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val=s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        int val=s1.top();
        return val;
        
    }
    
    bool empty() {
        return s1.empty();
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