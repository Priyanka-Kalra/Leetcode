class Solution {
    
    bool bipartite_bfs(vector<vector <int> > & graph,int node,vector <int> &colour){
        
        queue<pair<int,int> > order;
        
        order.push({node,0});
        while(!order.empty() ){
            
            pair<int,int> p=order.front();
            order.pop();
            colour[p.first]=p.second;
            
            for(int i=0;i<graph[p.first].size();i++){
                int temp=graph[p.first][i];
                if(colour[temp]==-1)order.push({temp,1-p.second});
                
                else if(colour[temp]==p.second)return false;
                
            }
            
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
                if(!bipartite_bfs(graph,i,colour))
                    return false;
            }
        }
        
        return true;
        
    }
};