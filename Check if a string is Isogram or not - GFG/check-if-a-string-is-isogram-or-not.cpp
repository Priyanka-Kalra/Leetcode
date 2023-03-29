//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        int n=s.size();
        if(n==1)return true;
        
        unordered_set<char> mp;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(mp.find(c)!=mp.end())return false;
            mp.insert(c);
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends