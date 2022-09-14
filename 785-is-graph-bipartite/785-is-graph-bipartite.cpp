class Solution {
    bool bipartite_dfs(vector<vector <int> > & graph,int node,int col,vector <int> &colour){
        
        colour[node]=col;
        
        for(int i=0;i<graph[node].size();i++){
            int temp=graph[node][i];
            
            if(colour[temp]==-1 && !bipartite_dfs(graph,temp,1-col,colour))
                return false;
            else if(colour[temp]==col)
                return false;
        }
        
        return true;
    }
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        //-1 for not visited/not coloured
        vector<int> colour(n,-1);
        
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                
                //graph,parent,colour 
                // if(!bipartite_bfs(graph,i,colour))
                //     return false;
                
                //graph,parent,col,colour 
                if(!bipartite_dfs(graph,i,0,colour))
                    return false;
            }
        }
        
        return true;
        
    }
};