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
    bool leaf(TreeNode *root){
        return (!root->left && !root->right);
    }
    void pathSum(TreeNode* root,int &targetSum,vector<int> &temp, vector<vector<int>> &answer){
        
        if(root==NULL)return;
        
        targetSum-=root->val;
        temp.push_back(root->val);
        if(targetSum==0 && leaf(root))answer.push_back(temp);
        
        pathSum(root->left,targetSum,temp,answer);
        pathSum(root->right,targetSum,temp,answer);
        
        targetSum+=root->val;
        temp.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> answer;
        vector<int> temp;
        pathSum(root,targetSum,temp,answer);
        return answer;
        
    }
};