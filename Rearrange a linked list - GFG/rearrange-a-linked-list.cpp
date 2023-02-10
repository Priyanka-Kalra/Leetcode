//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

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

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
        if(!head||!head->next)return ;
        
       Node * f_head=head;
       Node * s_head=head->next;
       
       Node * f_cur=head;
       Node * s_cur=head->next;
       Node * forward;
       
       while(f_cur && s_cur && s_cur->next){
           forward=s_cur->next;
           f_cur->next=forward;
           s_cur->next=forward->next;
           
           f_cur=forward;
           s_cur=forward->next;
       }
       
       f_cur->next=s_head;
       head=f_head;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends