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
    //https://www.youtube.com/watch?v=yyZA4v0x16w
    //similar to subarray with sum k,TC-O(N),SC-O(N)
    int count=0;
    void f(TreeNode* root, int targetSum,long sum,unordered_map<long,int> &mp){
        
        if(root==NULL)return;
        
        //operation on root node
        sum+=root->val;
        if(sum==targetSum)count++;
        if(mp.find(sum-targetSum)!=mp.end())count+=mp[sum-targetSum];
        mp[sum]++;
        
        //left and right node
        f(root->left,targetSum,sum,mp);
        f(root->right,targetSum,sum,mp);
        
        //backtrack
        if(mp[sum]>1)mp[sum]--;
        else mp.erase(sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)return 0;
        
        unordered_map<long,int> mp;
        long sum=0;
        f(root,targetSum,sum,mp);
        return count;
    }
};
/*

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
*/