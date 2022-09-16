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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        
        
        int width=0;
        
        queue<pair<TreeNode*,int> > order;
        order.push({root,0});
        while(!order.empty()){
            
            int size=order.size();
            int l_i,r_i;
            for(int i=0;i<size;i++){
                
                TreeNode* r=order.front().first;
                long dis=order.front().second;
                order.pop();
                if(i==0)l_i=dis;
                r_i=dis;
                
                if(r->left)order.push({r->left,2*dis +1});
                if(r->right)order.push({r->right,2*dis +2});
  
            }
            width=max(width,(r_i-l_i)+1);
               
        }
        return width;
    }
};