//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
//to maximize ∑arr[i]*i, arr[i] should be maximum for a given index.
//only possible if array is sorted
    public:
    int Maximize(int a[],int n)
    {
        
        sort(a,a+n);
        long sum=0;
        for(int i=0;i<n;i++)sum+=(long)a[i]*i;

        
        sum%=(1000000007);
        return (int)sum;
        
    }
};


//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends