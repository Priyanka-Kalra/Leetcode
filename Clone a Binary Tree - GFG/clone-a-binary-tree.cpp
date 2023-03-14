//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

//TC-O(N),SC-O(N)
class Solution{
  public:
    
    void duplicate(Node *A,unordered_map<Node*,Node*> &mp){
        
        if(!A)return;
        Node *n=new Node(A->data);
        mp[A]=n;
        duplicate(A->left,mp);
        duplicate(A->right,mp);
        
    }
    void update(Node *A,unordered_map<Node*,Node*> &mp){
        
        if(!A)return;
        mp[A]->left=mp[A->left];
        mp[A]->right=mp[A->right];
        mp[A]->random=mp[A->random];
        
        update(A->left,mp);
        update(A->right,mp);
        
    }
    
    Node* cloneTree(Node* tree)
    {
       //creating nodes
       unordered_map<Node*,Node*> mp;
       duplicate(tree,mp);
       
       //uodating the nodes
       update(tree,mp);
       return mp[tree];
       
    }
};


//{ Driver Code Starts.
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Solution obj;
     Node *t = obj.cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}


// } Driver Code Ends