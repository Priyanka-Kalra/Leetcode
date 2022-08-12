class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        
        int sum=0;
        int ans=0;
        for(auto it: nums){
            sum+=it;
            int c=sum%k;
            
            if(c==0)ans++;
            else if(c<0)c=c+k;//refer pepcoding for this change
            
            if(mp.find(c)!=mp.end()){
                ans+=mp[c];
            }
            mp[c]++;
        }
        
        return ans;
    }
};  
