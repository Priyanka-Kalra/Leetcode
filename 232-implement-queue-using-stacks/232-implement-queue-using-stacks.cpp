//https://www.youtube.com/watch?v=3Et9MrMc02A&t=249s
//1.using two stacks s1,s2(pop element one by one from s1 and push in s2.after this insert element (to be inserted) in s1.pop element one by one from s2 and push in s1.)TC-O(N) for push and TC-O(1)for rest


class MyQueue {
    
public:
    
    
    //2.TC-O(1) on average 
    stack<int> input;
    stack<int> output;
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int val=output.top();
            output.pop();
            return val;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int val=output.top();
        output.pop();
        return val;
        
    }
    
    int peek() {
        
        if(!output.empty()){
            int val=output.top();
            return val;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int val=output.top();
        return val;
        
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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