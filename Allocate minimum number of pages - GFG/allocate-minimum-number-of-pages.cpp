//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

//same logic used in leetcode 2187
//we use a range of load(low and high),and for each value we try to minimise the load for which books could be ditributed
class Solution 
{
    bool helper(int A[], int N, int M,int cur_load){
        
        int sum=0,student=1;
        for(int i=0;i<N;i++){
            sum+=A[i];
            
            if(sum>cur_load){
                student++;
                sum=A[i];
            }
        }
        return student<=M;
        
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
       if(M>N)return -1;
       
       int low=INT_MIN,high=0;
        for(int i=0;i<N;i++){
            low=max(low,A[i]);
            high+=A[i];
        }
        if(M==N)return low;
        
        int ans=INT_MAX;
        while(low<=high){
            
            int mid=(low+high)/2;
            if(helper(A,N,M,mid)){
                ans=min(ans,mid);
                high=mid-1;
                
            }
            else low=mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends