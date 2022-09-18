class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int N=nums.size();
        int n=N/2;
        
        int ans;
        unordered_set<int> mp;
        for(int i=0;i<N;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=nums[i];
                break;
            }
            mp.insert(nums[i]);
        }
        return ans;
    }
};
