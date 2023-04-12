//{ Driver Code Starts
// C++ implementation to check whether the array
// contains a set of contiguous integers
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    // Function to check whether the array contains
    // a set of contiguous integers
    bool areElementsContiguous(int arr[], int n)
    {
        
        int minV=INT_MAX,maxV=INT_MIN;
        for(int i=0;i<n;i++){
            minV=min(minV,arr[i]);
            maxV=max(maxV,arr[i]);
        }
        
        int range=maxV-minV+1;
        vector<int> present(range,false);
        for(int i=0;i<n;i++)present[arr[i]-minV]=true;
        
        for(int i=0;i<range;i++)if(!present[i])return 0;
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n + 1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        if (ob.areElementsContiguous(arr, n))
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
	return 0;
}

// } Driver Code Ends