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

//right most element of each level that is last of each level 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        //edge case
        if(root==NULL)return ans;
        
        queue<TreeNode *> order;
        order.push(root);
        
        while(!order.empty()){
            
            int size=order.size();
            for(int i=0;i<size;i++){
                
                TreeNode *cur=order.front();
                order.pop();
                
                if(i==size-1)ans.push_back(cur->val);
                
                if(cur->left)order.push(cur->left);
                if(cur->right)order.push(cur->right);
                
            }
            
        }
        return ans;
        
    }
};