//TC-O(N) can be improved to O(logN+k) by using binary search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        
        int ind=-1;
        
        //Edge cases:1.when x is lesser than first element(out of range)
        if(arr[0]>=x)ind=0;
        //Edge cases:2.when x is greater than largest element(out of range)
        else if(arr[n-1]<x)ind=n-1;
        if(ind==-1){
            for(int i=1;i<n;i++){
                
                if(arr[i]==x){
                    ind=i;
                    break;
                }
                //Edge cases:3. when x is in the range but not present in arr
                else if(arr[i-1]<x && arr[i]>x){
                    ind=x-arr[i-1]<= arr[i]-x ?i-1:i;
                    break;
                }
            }
        }
        
        int l=ind,r=ind;
        while(r-l+1!=k){
            if(l==0)r++;
            else if(r==n-1)l--;
            else if(x-arr[l-1] <=arr[r+1]-x) l--;
            else r++;
        }
        
        vector<int> ans;
        while(l<=r){
            ans.push_back(arr[l]);
            l++;
        }
        return ans;
    }
};