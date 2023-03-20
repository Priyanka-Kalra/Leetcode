//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
//refer notes//dp16
  public:
	int minDifference(int arr[], int n)  { 
	    
	    int target=0;
	    for(int i=0;i<n;i++)target+=arr[i];
	    
	    int k=target;
	    
	    vector<vector<bool> > dp(n,vector<bool> (k+1,0));
	    
	    //tabulation
	    for(int i=0;i<n;i++)dp[i][0]=1;
	    dp[0][arr[0]]=1;
	    for(int ind=1;ind<n;ind++){
	        for(int s=1;s<=k;s++){
	            bool take=arr[ind]<=s?dp[ind-1][s-arr[ind]]:0;
	            bool not_take=dp[ind-1][s];
	            dp[ind][s]=take||not_take;
	        }
	    }
	    
	    int ans=target;
	    for(int i=0;i<=target/2;i++){
	        if(dp[n-1][i]==true)ans=min(ans,abs(target-(2*i)));
	    }
	    
	    return ans;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends