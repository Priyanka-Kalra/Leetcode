class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        
        for(int i=n-3;i>=0;i--){
            int a=nums[i],b=nums[i+1],c=nums[i+2];
            
            if(a+b >c)return (a+b+c);
        }
        return 0;
    }
};