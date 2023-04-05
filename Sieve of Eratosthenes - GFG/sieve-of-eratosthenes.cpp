//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
//https://www.youtube.com/watch?v=pKvGYOnO9Ao&t=303s
//TC-O(N log(logN)),SC-O(N)
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<bool> v(n+1,1);
        for(int i=2;i<sqrt(n);i++){

            if(v[i]==0)continue;
            for(int j=i*i;j<=n;j=j+i)v[j]=0;
        
        }
        
        vector<int> ans;
        for(int i=2;i<=n;i++)if(v[i])ans.push_back(i);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends