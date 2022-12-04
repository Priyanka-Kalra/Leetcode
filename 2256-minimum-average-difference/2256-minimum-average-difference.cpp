class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        //[2,5,3,9,5,3]
        int n=nums.size();
        if(n==1)return 0;
        
        vector<long> pre(n,0);
        vector<long> pos(n,0);
        
        //[2,7,10,19,24,27]
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=nums[i]+pre[i-1];
        
        //[27,25,20,17,8,3]
        pos[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)pos[i]=nums[i]+pos[i+1];
        
        int minV=INT_MAX,ind=-1;
        for(int i=0;i<n-1;i++){
            int t1=pre[i]/(i+1);
            int t2=pos[i+1]/(n-i-1);
            int temp=abs(t1-t2);
            
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