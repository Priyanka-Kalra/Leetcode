//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void swap(int &a,int &b){
        int temp=b;
        b=a;
        a=temp;
    }
    void segregate0and1(int arr[], int n) {
        
        int low=0,high=n-1;
        while(low<=high){
            if(arr[low]==1){
                swap(arr[low],arr[high]);
                high--;
            }
            else low++;
        }
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
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends