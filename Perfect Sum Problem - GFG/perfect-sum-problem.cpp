//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    long long M=1000000007;
	public:
//1.Revursion,TC-O(2^N),SC-O(N)
// 	long long helper(int arr[],int ind,int target){
	    
// 	    if(ind==0){
// 	        if(target==0 || target==arr[0])return 1;
// 	        return 0;
// 	    }
	    
	    
// 	    return helper(arr,ind-1,target-arr[ind])+helper(arr,ind-1,target);
	    
// 	}
// 	int perfectSum(int arr[], int n, int sum)
// 	{
//         long long a=helper(arr,n-1,sum);
//         return (int)(a%M);
// 	}

//2.Memoization,TC-O(N*sum),SC-O(N*sum)
// 	int helper(vector<vector<int> > &dp,int arr[],int ind,int target){
	    
// 	    if(ind==0){
// 	        if(arr[0]==0 && target==0)return 2;//case when not pick and pick case will result in answer
// 	        else if(target==0 || target==arr[0])return 1;
// 	        return 0;
// 	    }
	    
// 	    if(dp[ind][target]!=-1)return dp[ind][target];
	    
// 	    int take=0,not_take=0;
// 	    if(arr[ind]<=target)take=helper(dp,arr,ind-1,target-arr[ind])%M;
// 	    not_take=helper(dp,arr,ind-1,target)%M;
// 	    return dp[ind][target]=(take+not_take)%M;
	    
// 	}
// 	int perfectSum(int arr[], int n, int sum)
// 	{
// 	    vector<vector<int> > dp(n,vector<int>(sum+1,-1));
//         return helper(dp,arr,n-1,sum);
         
// 	}

//3.Tabulation,TC-O(N*sum),SC-O(N*sum)
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int> > dp(n,vector<int>(sum+1,0));


	   for(int i=0;i<n;i++)dp[i][0]=1;
	   if(arr[0]<=sum)dp[0][arr[0]]=1;
	   if(arr[0]==0)dp[0][0]=2;
	   
	   for(int ind=1;ind<n;ind++){
	       for(int target=0;target<=sum;target++){
	           int take=0,not_take=0;
	           if(arr[ind]<=target)take=dp[ind-1][target-arr[ind]]%M;
	           not_take=dp[ind-1][target]%M;
	           dp[ind][target]=(take+not_take)%M;
	       }
	   }

        return dp[n-1][sum];
         
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends