/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//TC-O(N)
//SC-O(H)
class Solution {
    
    stack<TreeNode* > small;//left side
    stack<TreeNode* > large;//right side
    
    //true for left, false for right
public:
    
    void insert(TreeNode* root, bool isLeft){
        
        TreeNode* curr=root;
        while(curr){
            if(isLeft){
                small.push(curr);
                curr=curr->left;
            }
            else{
                large.push(curr);
                curr=curr->right;
            }
        }
    }
    
    int value(bool isLeft){
        if(isLeft){
            TreeNode* t=small.top();
            small.pop();
            insert(t->right,true);
            return t->val;
        }
        else{
            TreeNode* t=large.top();
            large.pop();
            insert(t->left,false);
            return t->val;
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        insert(root,true);
        insert(root,false);
        
        int i=value(true);
        int j=value(false);
        
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k)i=value(true);
            else j=value(false);
        }
        
        return false;
        
    }
};