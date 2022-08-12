class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > ans;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            
            int target=0-nums[i];
            
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[l]+nums[r]<target)l++;
                else if(nums[l]+nums[r]>target)r--;
                else{
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[l];
                    temp[2]=nums[r];
                    ans.push_back(temp);
                    
                    while(l<r && nums[l]==temp[1])l++;
                    while(l<r && nums[r]==temp[2])r--;
                }
            }
            
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        
        return ans;
    }
};