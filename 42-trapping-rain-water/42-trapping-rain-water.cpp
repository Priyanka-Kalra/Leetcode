class Solution {
public:
    /*
    //SC-O(N),TC-O(N)
    int trap(vector<int>& height) {
        
        int n=height.size();
        if(n<=2)return 0;
        
        vector<int> Pref(n);
        vector<int> Suff(n);
        
        Pref[0]=height[0];
        Suff[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            Pref[i]=max(Pref[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            Suff[i]=max(Suff[i+1],height[i]);
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            int t=min(Pref[i-1],Suff[i+1]) - height[i];
            if(t>0)ans+=t;
        }
        return ans;   
    }
    */
    //TC-O(N),SC-O(1)
    int trap(vector<int>& height){
        
        int n=height.size();
        if(n<=2)return 0;
        
        int l=0,r=n-1;
        int lmax=0;
        int rmax=0;
        
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>lmax)lmax=height[l];
                else{
                    int t=lmax-height[l];
                    if(t>0)ans+=t;
                }
                l++;
            }
            else{
                if(height[r]>rmax)rmax=height[r];
                else{
                    int t=rmax-height[r];
                    if(t>0)ans+=t;
                }
                r--;
            }
        }
        return ans;
        
    }
    
};