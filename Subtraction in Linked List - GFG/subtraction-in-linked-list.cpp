//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
//here we cant convert into integers or string due to out of range,so we have to manipulate the ll itself
Node *remove_Zeros(Node *h){
    while(h &&h->data==0)h=h->next;
    return h;
}
int size(Node *h){
    int count=0;
    while(h){
        h=h->next;
        count++;
    }
    return count;
}
void swapNode(Node * &h1,Node * &h2){
    Node *temp=h2;
    h2=h1;
    h1=temp;
}
void compare(Node * &l1,Node * &l2){
    
    int n1=size(l1),n2=size(l2);
    if(n1<n2)swap(l1,l2);
    else if(n1==n2){
        Node *t1=l1;
        Node *t2=l2;
        
        while(t1 && t1->data==t2->data ){
            t1=t1->next;
            t2=t2->next;
        }
        if(t1 && t1->data<t2->data)swap(l1,l2);
    }
}
Node *reverse(Node *h){
    Node * prev=NULL;
    Node * nxt;
    while(h->next){
        nxt=h->next;
        h->next=prev;
        prev=h;
        h=nxt;
    }
    h->next=prev;
    return h;
}
Node* subLinkedList(Node* l1, Node* l2)
{
    
    if(!l1)return l2;
    if(!l2)return l1;
    
    //removing zeros from begining
    l1=remove_Zeros(l1);
    l2=remove_Zeros(l2);
    if(!l1)return l2;
    if(!l2)return l1;
    
    //finding bigger ll
    compare(l1,l2);
    l1=reverse(l1);
    l2=reverse(l2);
    Node *h=l1;
    
    //performing subtraction
    bool borrow=false;
    while(l1){
        int c=borrow==true?-1:0;
        c+=l1->data;
        if(l2)c-=l2->data;
        
        if(c<0){
            c+=10;
            borrow=true;
        }
        else borrow=false;
        
        l1->data=c;
        l1=l1->next;
        if(l2)l2=l2->next;
    }
    
    
    Node *head=reverse(h);
    head=remove_Zeros(head);
    if(head==NULL){
        Node *n=new Node(0);
        return n;
    }
    else return head;
    
    
    
}