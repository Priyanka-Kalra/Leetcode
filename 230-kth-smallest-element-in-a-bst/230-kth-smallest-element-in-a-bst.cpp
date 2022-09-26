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
class Solution {
    int kthSmallest(TreeNode* root, int k,int &count){
        
        if(root==NULL)return 0;;
        
        int l=kthSmallest(root->left,k,count);
        if(l!=0)return l;
        count++;
        if(count==k)return root->val;
        
        return kthSmallest(root->right,k,count);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        
        return kthSmallest(root,k,count);
    }
};