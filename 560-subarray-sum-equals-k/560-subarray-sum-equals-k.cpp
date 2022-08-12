class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            int temp=sum-k;
            
            if(sum==k)ans++;
            
            if(mp.count(temp)>0)
                ans+=mp[temp];
            
            mp[sum]++;
        }
        return ans;
    }
};