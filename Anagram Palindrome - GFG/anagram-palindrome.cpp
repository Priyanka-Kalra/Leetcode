//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

//check for count of each alphabet.Palindrome is only possible if
//case1-if string is of even length and all alphabetic count is even 
//case2-if string is of odd length and all alphabetic count is even and only one alphabet occurs once


int isPossible (string S)
{
    
    int size=S.size();
    unordered_map<char,int> mp;
    for(int i=0;S[i]!='\0';i++)mp[S[i]]++;
    
    bool single=false;
    for(auto i:mp){
        if(i.second%2==0)continue;
        else if(size%2==0)return 0;
        else if(single)return 0;
        else single=true;
    }
    return 1;
}