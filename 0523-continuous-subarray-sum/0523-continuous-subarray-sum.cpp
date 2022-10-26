//form a prefix array(say arr)
//then for each value(i) of arr, check for the remainder(say r,r=i%k).
//case1 - r==0 return truw;
//case2 - r!=0 and r is present in map(such that length >=2)return true
//case3 - else return false;
class Solution {
public:
    
    //[0,1,0,3,0,4,0,4,0],k=5
    //0 1 1 4 4 8 8 12 12
    //0 1 1
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size()==1)return false;
        
        vector<int> arr;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            arr.push_back(sum);
        }

        unordered_map<int,int> mp;
        int n=arr.size();
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
