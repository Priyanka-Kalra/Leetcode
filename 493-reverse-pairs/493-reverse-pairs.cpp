class Solution {
    int Merge(int si,int ei,int mid,vector<int>& nums){
        
        int n=ei-si+1;
        int count=0;
        
        //2 3 4   1 5
        //calculative part
        int i=si,j=mid+1;
        for(;i<=mid;i++){
            while(j<=ei && nums[i]> 2LL *nums[j])j++;
            
            count+=(j-mid-1);
        }
        
        //actual merge
        vector<int> temp(n);
        
        i=si;
        j=mid+1;
        int k=0;
        while(i<=mid && j<=ei){
            if(nums[i]<nums[j]){
                temp[k]=nums[i];
                k++;
                i++;
            }
            else{
                temp[k]=nums[j];
                k++;
                j++;
            }
        }
        while(i<=mid){
            temp[k]=nums[i];
            k++;
            i++;
        }
        while(j<=ei){
            temp[k]=nums[j];
            k++;
            j++;
        }
        
        for(int i=0;i<n;i++)
            nums[i+si]=temp[i];
        
        return count;
    }
    
    int MergeS(int si,int ei,vector<int>& nums){
        if(si>=ei)return 0;
        
        int count=0;
        int mid=(si+ei)/2;
        count+=MergeS(si,mid,nums);
        count+=MergeS(mid+1,ei,nums);
        count+=Merge(si,ei,mid,nums);
        return count;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        
        if(nums.size()==1)return 0;
        
        return MergeS(0,nums.size()-1,nums);
    }
};