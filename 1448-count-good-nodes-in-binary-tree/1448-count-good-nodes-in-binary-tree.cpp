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
    void goodNodes(TreeNode* root,int &count,int max_val){
        
        if(root==NULL)return;
        
        if(max_val<=root->val){
            count++;
            max_val=root->val;
        }
        goodNodes(root->left,count,max_val);
        goodNodes(root->right,count,max_val);
    }
public:
    int goodNodes(TreeNode* root) {
        
        if(!root->left && !root->right)return 1;
        
        int count=0;
        goodNodes(root,count,INT_MIN);
        return count;
    }
};