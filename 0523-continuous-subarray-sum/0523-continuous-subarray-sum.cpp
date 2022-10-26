//form a prefix array(say arr)
//then for each value(i) of arr, check for the remainder(say r,r=i%k).
//case1 - r==0 return truw;
//case2 - r!=0 and r is present in map(such that length >=2)return true
//case3 - else return false;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==1)return false;
        
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++)arr.push_back(arr[i-1]+nums[i]);
        

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int r=arr[i]%k;
            
            if(r==0 && i>=1)return true;
            else if(mp.find(r)!=mp.end()){
                if(i-mp[r]>=2)return true;
            }
            else mp[r]=i;
        }
        return false;
    }
};
