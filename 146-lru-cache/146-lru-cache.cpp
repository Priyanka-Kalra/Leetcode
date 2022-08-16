//https://www.youtube.com/watch?v=xDEuM5qa0zg&t=10s
class dll{
    public:
    int key;
    int value;
    dll *prev;
    dll* next;
    
    dll(){
        prev=NULL;
        next=NULL;
    }
    dll(int key,int value){
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
    int capacity;
    unordered_map<int,dll*> mp;
    dll *head;
    dll *tail;
    
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new dll();
        tail=new dll();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)==0)return -1;
        
        int val=mp[key]->value;
        
        //removing node from previous position 
        dll *temp=mp[key];
        dll *p_temp=temp->prev;
        dll *n_temp=temp->next;
        
        p_temp->next=n_temp;
        n_temp->prev=p_temp;
        
        //insert removed node,next to head
        temp->next=head->next;
        head->next=temp;
        temp->next->prev=temp;
        temp->prev=head;
        
        return val;
        
    }
    
    void put(int key, int value) {
        if(mp.count(key)>0){
            dll *temp=mp[key];
            temp->value=value;
            
            //removing node from previous position 
            dll *p_temp=temp->prev;
            dll *n_temp=temp->next;
            
            p_temp->next=n_temp;
            n_temp->prev=p_temp;
            
            //insert removed node,next to head
            temp->next=head->next;
            head->next=temp;
            temp->next->prev=temp;
            temp->prev=head;
            return;
        }
        
        //check for size
        if(mp.size()==capacity){
            dll *t=tail->prev;
            int k=t->key;
            mp.erase(k);
            
            dll *pt=t->prev;
            pt->next=tail;
            tail->prev=pt;
            
        }
        
        dll *node=new dll(key,value);
        node->next=head->next;
        head->next=node;
        node->next->prev=node;
        node->prev=head;
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */