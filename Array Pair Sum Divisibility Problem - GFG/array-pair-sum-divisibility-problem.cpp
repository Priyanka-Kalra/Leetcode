//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        unordered_map<int,int> mp;
        int n=arr.size(),pairs=0;
        if(n%2!=0)return false;

        for(int i=0;i<n;i++){

            int x=arr[i]%k;
            if(x<0)x+=k;
            if(x==0 && mp.find(0)!=mp.end()){
                pairs++;
                if(mp[0]==1)mp.erase(0);
                else mp[0]--;
            }
            else if(mp.find(k-x)!=mp.end()){
                pairs++;
                if(mp[k-x]==1)mp.erase(k-x);
                else mp[k-x]--;
            }
            else mp[x]++;
        }

        return pairs*2==n;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends