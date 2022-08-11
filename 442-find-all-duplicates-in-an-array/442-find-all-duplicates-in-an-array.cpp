class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int n=nums.size();
        if(n==1)return ans;
        
        for(auto it: nums){
            int ind=abs(it) -1;
            
            if(nums[ind]<0)ans.push_back(ind+1);
            else nums[ind]*=-1;
        }
        return ans;
        
    }
};