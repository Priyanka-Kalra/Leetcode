class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int a,b,c;
        for(int i=n-3;i>=0;i--){
            a=nums[i];
            b=nums[i+1];
            c=nums[i+2];
            
            if(b+a>c)return (a+b+c);
        }
        return 0;
    }
};