//make it yourself
class Node{
    public:
    int val;
    Node *next;
    
    Node(int val=-1){
        
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
    Node *head;
    int size;
    
public:
    MyLinkedList(){
        head=new Node(0);
        size=0;
    }
    
    int get(int index) {
        if(index>size-1)return -1;
        
        Node *temp=head->next;
        for(int i=0;i<index;i++)temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        // Node *temp=new Node(val);
        // temp->next=head->next;
        // head->next=temp;
        // size++;
        addAtIndex(0,val);
        
    }
    
    void addAtTail(int val) {
        Node *temp=new Node(val);
        Node *cur=head;
        while(cur->next)cur=cur->next;
        
        cur->next=temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)return;
        
        Node *temp=new Node(val);
        
        Node *cur=head;
        for(int i=0;i<index;i++)cur=cur->next;
        temp->next=cur->next;
        cur->next=temp;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>size-1)return;
        
        
        Node *cur=head;
        for(int i=0;i<index;i++)cur=cur->next;
        Node *temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */