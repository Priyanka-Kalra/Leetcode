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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        queue<TreeNode* > order;
        order.push(root);
        
        while(!order.empty()){
            
            int size=order.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode *r=order.front();
                order.pop();
                
                sum+=r->val;
                if(r->left)order.push(r->left);
                if(r->right)order.push(r->right);
            }
            sum/=(double)size;
            ans.push_back(sum);
        }
        
        return ans;
    }
};