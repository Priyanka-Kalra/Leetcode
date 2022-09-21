class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int N=nums.size();
        int sum=0;
        for(auto i:nums)if(i%2==0)sum+=i;
        
        vector<int> ans;
        int n=queries.size();
        int ind,val;
        for(int i=0;i<n;i++){
            
            ind=queries[i][1];
            val=queries[i][0];
            
            if(nums[ind]%2==0)sum-=nums[ind];
            nums[ind]+=val;
            if(nums[ind]%2==0)sum+=nums[ind];
                
    
            
            ans.push_back(sum);  
        }
        
        return ans;
        
    }
};
//[7,2]
//[[4,0],[3,0]]
//[2 ]