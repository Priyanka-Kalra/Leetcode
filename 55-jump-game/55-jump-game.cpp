class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return true;
        
        int goalPost=n-1;
        int i=n-2;
        while(i>=0){
            if(nums[i]+i>=goalPost)goalPost=i;
            
            i--;
        }
        
        if(goalPost==0)return true;
        return false;
    }
};