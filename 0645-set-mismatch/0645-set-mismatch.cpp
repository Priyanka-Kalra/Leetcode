//1.arithmetic way(will not pass bcz of out of range due to products)
//2.index
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(2);
        
        //ans=2,
        //[2,-2]
        for(auto i:nums){
            int ind=abs(i)-1;
            if(nums[ind]<1)ans[0]=abs(i);
            else nums[ind]*=-1;
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};