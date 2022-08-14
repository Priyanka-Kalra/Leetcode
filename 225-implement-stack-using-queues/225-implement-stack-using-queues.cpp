//https://www.youtube.com/watch?v=jDZQKzEtbYQ
//1.using 2 queues(push elemnt in q2, now pop elements from q1 one by one and push in q2 till q1 is empty. now swap q1 and q2)

//2.one queues(push element in q,now if size>1,pop element and push it back til(size-1)times)
class MyStack {
    
    queue<int> Q;
public:
    /*
    //1.
    void push(int x) {
        queue<int> P;
        P.push(x);
        while(!Q.empty()){
            P.push(Q.front());
            Q.pop();
            
        }
        while(!P.empty()){
            Q.push(P.front());
            P.pop();
        }
        
    }
    
    int pop(){
        int val=Q.front();
        Q.pop();
        return val; 
    }
    
    int top() {
        int val=Q.front();
        return val;
        
    }

    bool empty() {
        return (Q.empty());
    }
    */
    
    //2.

    void push(int x) {
        Q.push(x);
        int size=Q.size();
        while(size>1){
            int t=Q.front();
            Q.pop();
            size--;
            Q.push(t);
        }
    }
    
    int pop() {
        int t=Q.front();
        Q.pop();
        return t;
        
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
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