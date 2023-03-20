//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    pair<int,int> helper(int N,int A[]){
        
        int maxV=A[0],minV=A[0];
        for(int i=1;i<N;i++){
            maxV=max(maxV,A[i]);
            minV=min(minV,A[i]);
        }
        
        return {minV,maxV};
        
    }
    
  public:
    int countElements(int N, int A[]) {
        
        if(N==1)return 0;
        
        pair<int,int> p=helper(N,A);//min.max
        int ans=p.second-p.first-1;
        
        unordered_set<int> mp;
        for(int i=0;i<N;i++)if(A[i]!=p.second && A[i]!=p.first)mp.insert(A[i]);
        
        ans-=mp.size();
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}
// } Driver Code Ends