//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	bool sameFreq(string s)
	{
	    int n=s.size();
	    if(n==1)return true;
	    
	    unordered_map<char,int> frequency;//char,frequency
	    int minF=INT_MAX,maxF=0;
	    for(int i=0;i<n;i++)frequency[s[i]]++;

	    
	    
	    unordered_map<int,int> count;//frequency,number of elements with the respective requency
	    for(auto i:frequency)count[i.second]++;
	        
	    
	    if(count.size()>2)return 0;
	    if(count.size()==1)return 1;
	    
	    if(count.find(1)!=count.end() && count[1]==1)return 1;//abababc
	    vector<int> temp;
	    for(auto i:count)temp.push_back(i.first);
	    if(abs(temp[0]-temp[1])>1)return 0;
	    if(temp[0]>temp[1] && count[temp[0]]==1)return 1;
	    if(temp[1]>temp[0] && count[temp[1]]==1)return 1;
	    

	    return false;
	   
	}
//xxxyyzz
//abababc
//aabbbccddd
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends