//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
//dp 18
//refer dp notes
    long long M=1000000007;
//1.Recursion,TC-O(2^N)
//     int helper(vector<int>& arr,int ind,int curSum){
        
//         if(ind<0){
//             if(curSum==0)return 1;
//             return 0;
//         }
        
//         int take=0,not_take=0;
//         take=helper(arr,ind-1,curSum-arr[ind])%M;
//         not_take=helper(arr,ind-1,curSum)%M;
        
//         return (take+not_take)%M;
//     }
//   public:
//     int countPartitions(int n, int d, vector<int>& arr) {
        
//         int sum=0;
//         for(int i=0;i<n;i++)sum+=arr[i];
        
//         int target=(sum-d)/2;
//         return helper(arr,n-1,target);
//     }

//2.Memoization
//     int helper(vector<vector<int> > &dp,vector<int>& arr,int ind,int target){
        
        
//         if(ind==0){
//             if( arr[0]==0 && target==0 )return 2;
//             if(target==0 || arr[0]==target )return 1;
//             return 0;
//         }
        
//         if(dp[ind][target]!=-1)return dp[ind][target];
        
//         int take=0,not_take=0;
//         if(arr[ind]<=target)take=helper(dp,arr,ind-1,target-arr[ind])%M;
//         not_take=helper(dp,arr,ind-1,target)%M;
        
//         return dp[ind][target]=(take+not_take)%M;
//     }
//   public:
//     int countPartitions(int n, int d, vector<int>& arr) {
        
//         int Tsum=0;
//         for(int i=0;i<n;i++)Tsum+=arr[i];
        
        
//         int target=(Tsum-d)/2;
//         if(target<0 || target*2!=Tsum-d)return 0;
        
//         vector<vector<int> > dp(n,vector<int> (target+1,-1));
//         return helper(dp,arr,n-1,target);
//     }

//3.Tabulation
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int Tsum=0;
        for(int i=0;i<n;i++)Tsum+=arr[i];
        
        
        int target=(Tsum-d)/2;
        if(target<0 || target*2!=Tsum-d)return 0;
        
        vector<vector<int> > dp(n,vector<int> (target+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(arr[0]<=target)dp[0][arr[0]]=1;
        if(arr[0]==0)dp[0][0]=2;
        
        for(int ind=1;ind<n;ind++){
            for(int curS=0;curS<=target;curS++){
                
                int take=0,not_take=0;
                if(arr[ind]<=curS)take=dp[ind-1][curS-arr[ind]]%M;
                not_take=dp[ind-1][curS]%M;
                
                dp[ind][curS]=(take+not_take)%M;
            }
        }
        
        
        return dp[n-1][target];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends