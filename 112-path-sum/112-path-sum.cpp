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
    bool isLeaf(TreeNode* root){
        return (!root->left && !root->right);
    }
    bool hasPathSum(TreeNode* root, int &curSum,int targetSum){
        if(root==NULL)return false;
        
        curSum+=root->val;
        if(curSum==targetSum && isLeaf(root))return true;
        
        bool l=hasPathSum(root->left,curSum,targetSum);
        bool r=hasPathSum(root->right,curSum,targetSum);
        curSum-=root->val;
        
        return (l|| r);
    } 
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)return false;
        
        int curSum=0;
        return hasPathSum(root,curSum,targetSum);
    }
};