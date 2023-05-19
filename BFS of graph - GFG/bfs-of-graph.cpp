//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void traverse(int node,int V,vector<bool> &visited,vector<int> &bfs, vector<int> adj[]){
        
        queue<int> order;
        order.push(node);
        visited[node]=1;
        while(!order.empty()){
            
            int n=order.front();
            order.pop();
            bfs.push_back(n);
            for(int i=0;i<adj[n].size();i++){
                if(visited[adj[n][i]]==0){
                    visited[adj[n][i]]=1;
                    order.push(adj[n][i]);
                }
                
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        

        vector<bool> visited(V,0);
        vector<int> bfs;

        queue<int> order;
        order.push(0);
        visited[0]=1;
        
        while(!order.empty()){
            
            int n=order.front();
            order.pop();
            bfs.push_back(n);
            for(int i=0;i<adj[n].size();i++){
                if(visited[adj[n][i]]==0){
                    visited[adj[n][i]]=1;
                    order.push(adj[n][i]);
                }
                
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends