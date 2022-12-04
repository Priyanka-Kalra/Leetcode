class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return 0;
        
        vector<long> pre(n);
        vector<long> pos(n);
        
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=nums[i]+pre[i-1];
        
        pos[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)pos[i]=nums[i]+pos[i+1];
        
        int minV=INT_MAX,ind=-1;
        for(int i=0;i<n-1;i++){

            int temp=abs( (pre[i]/(i+1)) -(pos[i+1]/(n-i-1)) );
            if(temp<minV){
                minV=temp;
                ind=i;
            } 
        }
        
        int temp=pre[n-1]/n;
        if(temp<minV)ind=n-1;
        
        return ind;
    }
};