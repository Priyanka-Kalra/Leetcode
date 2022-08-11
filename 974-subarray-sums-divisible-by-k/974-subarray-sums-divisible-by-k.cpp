class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //storing the frequency of remainders and adding (freuency of a remainder -1) to ans
        unordered_map<int,int> mp;
        mp[0]=1;
        
        int sum=0;
        int ans=0;
        for(auto it: nums){
            sum+=it;
            int c=sum%k;
            
            if(c>=0)mp[c]++;
            else {
                c=k+c;
                mp[c]++;
            }
            
            ans+=mp[c]-1;
        }
        
        return ans;
    }
};  
