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
    void addOneRow(TreeNode* root, int val,int level, int depth){
        
        if(!root)return;
        
        if(level==depth-1){
            TreeNode * nL=new TreeNode(val);
            TreeNode * nR=new TreeNode(val);
            
            if(root->left)nL->left=root->left;
            if(root->right)nR->right=root->right;
            
            root->left=nL;
            root->right=nR;
            
            
            return;
        }
        
        
        addOneRow(root->left,val,level+1,depth);
        addOneRow(root->right,val,level+1,depth);
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode * n=new TreeNode(val);
            n->left=root;
            return n;
        }
        
        int level=1;
        addOneRow(root,val,level,depth);
        return root;
    }
    
};