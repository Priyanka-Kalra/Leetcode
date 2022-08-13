class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int el1,el2;
        int count1=0,count2=0;
        
        for(auto it: nums){
            if(count1==0 && it!=el2)el1=it;//and condition is used for case when count2!=0 and count1==0 but nums[i]==el2
            else if(count2==0)el2=it;
            
            if(it==el1)count1++;
            else if(it==el2)count2++;
            else{
                count1--;
                count2--;
            }
        }
        
        count1=count2=0;
        for(auto it:nums){
            if(it==el1)count1++;
            else if(it==el2)count2++;
        }
        
        vector<int> ans;
        if(count1>(n/3))ans.push_back(el1);
        if(count2>(n/3))ans.push_back(el2);
        
        return ans;
    }
};