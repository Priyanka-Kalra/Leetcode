//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

//find number of positions from which number1 is displaced.
//in sorted array, 1 is at 0 index

//Approach1-use linear search tp find smallest.
//Approach2-use binary search to find condition arr[mid-1]>arr[mid]&&arr[mid]<arr[mid+1]
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	   
	   int l=0,r=n-1;
	   
	   if(arr[l]<=arr[r])return 0;
	   
	   while(l<=r){
	       int mid=(l+r)/2;
	       int prev=(mid-1+n)%n;
	       int nxt=(mid+1)%n;
	       
	       if(arr[prev]>=arr[mid]&& arr[mid]<=arr[nxt])return mid;
	       else if(arr[mid]<=arr[r])r=mid-1;
	       else l=mid+1;
	       
	       
	   }
	   
	   return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends