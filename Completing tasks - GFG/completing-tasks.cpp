//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        
        unordered_set<int> mp;
        for(int i=0;i<m;i++)mp.insert(arr[i]);
        
        vector<int> a1;
        vector<int> a2;
        int k=0;
        for(int i=1;i<=n;i++){
            if(mp.find(i)!=mp.end())continue;
            
            if(k==0){
                a1.push_back(i);
                k=1;
            }
            else{
                a2.push_back(i);
                k=0;
                    
            }
            
        }
        
        return {a1,a2};
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends