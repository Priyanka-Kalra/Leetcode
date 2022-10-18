class CustomStack {
    
    int *stack;
    int size,capacity;
public:
    CustomStack(int maxSize) {
        stack=new int[maxSize];
        capacity=maxSize;
        size=0;
    }
    
    void push(int x) {
        if(size==capacity)return;
        
        stack[size]=x;
        size++;
    }
    
    int pop() {
        if(size==0)return -1;
        
        int el=stack[size-1];
        size--;
        return el;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k&& i<capacity;i++)stack[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */