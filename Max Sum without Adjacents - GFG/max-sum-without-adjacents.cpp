//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	//1.recursion TC-O(2^N), SC-O(N)
// 	int findMaxSum(int *arr, int n) {
//      if(n<1)return 0;
// 	    if(n==1)return arr[0];
	    
// 	    int l=INT_MIN,r=INT_MIN;
// 	    l=arr[n-1]+findMaxSum(arr,n-2);
// 	    r=findMaxSum(arr,n-1);
// 	    return max(l,r);
// 	}
	
	//2.Memoization, TC-O(N), SC-O(N)
// 	int help_findMaxSum(vector<int> &dp,int *arr, int index){
// 	    if(index<0)return 0;
// 	    if(index==0)return dp[0]=arr[0];
	    
// 	    if(dp[index]!=-1)return dp[index];
	    
// 	    int l=INT_MIN,r=INT_MIN;
// 	    l=arr[index]+help_findMaxSum(dp,arr,index-2);
// 	    r=help_findMaxSum(dp,arr,index-1);
// 	    return dp[index]=max(l,r);
	    
// 	}
// 	int findMaxSum(int *arr, int n) {
// 	    vector<int> dp(n,-1);
// 	    return help_findMaxSum(dp,arr,n-1);
// 	}

    //3.Tabulation, TC-O(N), SC-O(N)
//     int findMaxSum(int *arr, int n) {
// 	    vector<int> dp(n,-1);
// 	    dp[0]=arr[0];
// 	    for(int i=1;i<n;i++){
	        
// 	        int l=arr[i];
//          if(i-2>=0)l+=dp[i-2];

// 	        int r=dp[i-1];
// 	        dp[i]=max(l,r);
// 	    }
// 	    return dp[n-1];
// 	}

    //4.Tabulation with space optimization, TC-O(N), SC-O(1)
    int findMaxSum(int *arr, int n) {
	    
	    int prev1=0,prev2=arr[0];

	    for(int i=1;i<n;i++){
	        
	        int temp=max(prev1+arr[i],prev2);
	        prev1=prev2;
	        prev2=temp;
	    }
	    return prev2;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends