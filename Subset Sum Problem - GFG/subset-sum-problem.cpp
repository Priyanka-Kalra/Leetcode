//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

//1.brute force-make all subsets and find the sum

//User function template for C++

//1.brute force-make all subsets and find the sum

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
    bool helper(vector<vector<int> > &dp,vector<int>arr,int ind,int target){
        
        
        if(target==0)return dp[ind][target]=1;
        if(ind==0)return dp[ind][target]=arr[0]==target;
        
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        
        bool take=arr[ind]<=target?helper(dp,arr,ind-1,target-arr[ind]):false;
        bool not_take=helper(dp,arr,ind-1,target);
        return dp[ind][target] =take || not_take;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        n=arr.size();
        vector<vector<int> > dp(n,vector<int> (sum+1,-1));
        //-1 if not visited.1/0 for true/false
        
        return helper(dp,arr,n-1,sum);
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