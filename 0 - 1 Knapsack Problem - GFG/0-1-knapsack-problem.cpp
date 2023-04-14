//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int ans;
    public:
    
    //1.Recursion,TC-O(2^N)
    // void helper(int cur_val,int W, int wt[], int val[], int ind){
        
    //     if(ind==0){
    //         int t=wt[0]<=W?val[0]:0;
    //         ans=max(ans,cur_val+t);
    //         return;
    //     }
        
    //     //take
    //     if(wt[ind]<=W)helper(cur_val+val[ind],W-val[ind],wt,val,ind-1);
        
    //     //not take
    //     helper(cur_val,W,wt,val,ind-1);
    // }
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     ans=0;
    //     helper(0,W,wt,val,n-1);
    //     return ans;
       
    // }
    
    //2.Memoization,TC-O(N*W),SC-O(N*W)
    // int helper(vector<vector<int>> &dp,int W, int wt[], int val[], int ind){
        
    //     if(ind==0){
    //         return wt[0]<=W?val[0]:0;
    //     }
        
    //     if(dp[ind][W]!=-1)return dp[ind][W];
        
        
    //     int take=-1,not_take=-1;
    //     if(wt[ind]<=W)take=val[ind]+helper(dp,W-wt[ind],wt,val,ind-1);
    //     not_take=helper(dp,W,wt,val,ind-1);
        
    //     return dp[ind][W]=max(take,not_take);
    // }
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     vector<vector<int>> dp(n,vector<int>(W+1,-1));
    //     return helper(dp,W,wt,val,n-1);
        
       
    // }
    
    //3.Tabulation,TC-O(N*W),SC-O(N*W)
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int i=0;i<=W;i++)if(wt[0]<=i)dp[0][i]=val[0];
        
        for(int i=1;i<n;i++){
            for(int cur_wt=0;cur_wt<=W;cur_wt++){
                int take=-1,not_take=-1;
                if(wt[i]<=cur_wt)take=val[i]+dp[i-1][cur_wt-wt[i]];
                not_take=dp[i-1][cur_wt];
                
                dp[i][cur_wt]=max(take,not_take);
            }
        }
        
        return dp[n-1][W];
        
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends