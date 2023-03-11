//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++



//User function template for C++



class Solution{ 
    int n;

public:
//Recursive,TC-O(2^N)
    // bool helper(vector<int>arr,int ind,int target){
        
    //     if(0==target)return true;
    //     if(target<0)return false;
    //     if(ind<0)return false;
        
    //     return (helper(arr,ind-1,target-arr[ind])||helper(arr,ind-1,target));
        
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
        
    //     n=arr.size();
    //     return helper(arr,n-1,sum);
    // }

//Memoization,TC-O(n*sum)
    // bool helper(vector<vector<int> > &dp,vector<int>arr,int ind,int target){
        
        
    //     if(target==0)return dp[ind][target]=1;
    //     if(ind==0)return dp[ind][target]=arr[0]==target;
        
        
    //     if(dp[ind][target]!=-1)return dp[ind][target];
        
        
    //     bool take=arr[ind]<=target?helper(dp,arr,ind-1,target-arr[ind]):false;
    //     bool not_take=helper(dp,arr,ind-1,target);
    //     return dp[ind][target] =take || not_take;
        
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     n=arr.size();
    //     vector<vector<int> > dp(n,vector<int> (sum+1,-1));
    //     //-1 if not visited.1/0 for true/false
        
    //     return helper(dp,arr,n-1,sum);
    // }

//Tabulation(different implementation used in leetcode 416)
    bool isSubsetSum(vector<int>arr, int sum){
        n=arr.size();
        vector<vector<bool> > dp(n,vector<bool> (sum+1,0));
        
        for(int i=0;i<n;i++)dp[i][0]=true;
        dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool take=arr[ind]<=target?dp[ind-1][target-arr[ind]]:false;
                bool not_take=dp[ind-1][target];
                dp[ind][target] =take || not_take;
            }
        }
        
        
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends