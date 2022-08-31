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
//for each node calculate path sum,TC-O(N^2),SC-O(N)(due to recursion)
class Solution {
public:
    int count=0;
    
    void f(TreeNode* root, int targetSum,long sum){
        
        if(root==NULL)return;
        
        sum+=root->val;
        if(sum==targetSum)count++;//we are not returning because further nodes may contain 0 so therefore a unique combination,eg 3+5=8 and 3+5+0=8
        f(root->left,targetSum,sum);
        f(root->right,targetSum,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        
        f(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return count;
        
    }
};