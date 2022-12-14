class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>> answer;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                long long temp_targ=target-(long long)(nums[i]+nums[j]);
                
                int l=j+1;
                int r=n-1;
                while(l<r){
                    
                    long long s=nums[l]+nums[r];
                    
                    if(s<temp_targ)l++;
                    else if(s>temp_targ)r--;
                    else{
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[l];
                        temp[3]=nums[r];
                        
                        answer.push_back(temp);
                        while(l<r && nums[l]==temp[2])l++;
                        while(l<r && nums[r]==temp[3])r--;
                    } 
                }
                
                while(j+1<n && nums[j]==nums[j+1])j++;
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        
        return answer;
    }
};