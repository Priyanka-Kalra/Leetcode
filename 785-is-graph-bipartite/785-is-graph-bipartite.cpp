class Solution {
    
    bool bipartite_bfs(vector<vector <int> > & graph,int node,vector <int> &colour){
        
        queue<pair<int,int> > order;
        
        order.push({node,0});
        while(!order.empty() ){
            
            pair<int,int> p=order.front();
            order.pop();
            
            int val=p.first;
            int col=p.second;
            colour[val]=col;
            
            for(int i=0;i<graph[val].size();i++){
                int temp=graph[val][i];
                if(colour[temp]==-1)order.push({temp,1-col});
                
                else if(colour[temp]==col)return false;
                
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