//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.size()!=str2.size())return false;
        
        unordered_map<char,int> mp;
        for(int i=0;str1[i]!='\0';i++)mp[str1[i]]++;
        
        int count=0;
        for(int i=0;str2[i]!='\0';i++){
            char c=str2[i];
            if(mp[c]>0)mp[c]--;
            else count++;
        }
        
        return count<=k;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends