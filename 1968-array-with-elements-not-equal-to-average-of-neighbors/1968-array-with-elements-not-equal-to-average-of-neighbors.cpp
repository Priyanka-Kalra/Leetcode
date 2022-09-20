//https://www.youtube.com/watch?v=Wmb3YdVYfqM
//TC-O(N logN)
//for nums[i]!=avg(nums[i-1],nums[i+1]),there are 2 options that avg comes out to be greater than nums[i] or lesser than nums[i]
//for avg to be greater we have to fill every alternate number with largest available number, but its difficult to keep up
//so instead, we sort and fill alternate positions with smallest first so that avg comes out to be smaller
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> ans;
        sort(nums.begin(),nums.end());
        
        int l=0,r=n-1;
        for(int i=0;i<n;i++){
            
            if(i%2==0){
                ans.push_back(nums[l]);
                l++;
            }
            else{
                ans.push_back(nums[r]);
                r--;
            }
            
        }
        
        return ans;
    }
};
