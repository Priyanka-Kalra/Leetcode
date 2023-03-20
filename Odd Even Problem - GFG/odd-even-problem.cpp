//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        
        int n=S.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)mp[S[i]]++;
        
        int X=0,Y=0;
        for(auto i:mp){
            int ascii=i.first;
            int count=i.second;
            
            if(ascii%2==0 && count%2==0)X++;
            else if(ascii%2!=0 && count%2!=0)Y++;
        }
        
        string ans="";
        if((X+Y)%2==0)ans+="EVEN";
        else ans+="ODD";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}

// } Driver Code Ends