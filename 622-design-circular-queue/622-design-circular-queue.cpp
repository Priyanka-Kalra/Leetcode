class MyCircularQueue {
    int *arr;
    int size,capacity,front,rear;
public:
    
    MyCircularQueue(int k) {
        arr=new int[k];
        size=0;
        capacity=k;
        front=-1;
        rear=-1;
        
    }
    
    bool enQueue(int value) {
        
        if(size==capacity)return false;
        
        if(size==0)front=0;
        rear=(rear+1)%capacity;
        arr[rear]=value;
        size++;
        return true;
        
    }
    
    bool deQueue() {
        if(size==0)return false;
        
        front=(front+1)%capacity;
        size--;
        if(size==0){
            front=-1;
            rear=-1;
        }
        return true;
    }
    
    int Front() {
        if(size==0)return -1;
        return arr[front];
    }
    
    int Rear() {
        if(size==0)return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */