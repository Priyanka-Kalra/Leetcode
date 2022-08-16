class Solution {
    void bfs(int node,vector<int> *adjList,vector<int> &visited){
        
        queue<int> order;
        order.push(node);
        while(!order.empty()){
            int t=order.front();
            order.pop();
            visited[t]=0;
            for(int i=0;i<adjList[t].size();i++){
                int val=adjList[t][i];
                if(visited[val]==-1)
                    order.push(val);
            }
            
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v=isConnected.size();
        vector<int> adjList[v+1];
        
        //create adjancy list
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1&& i!=j){
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        
        int count=0;
        vector<int> visited(v+1,-1);
        for(int i=1;i<=v;i++){
            if(visited[i]==-1){
                bfs(i,adjList,visited);
                count++;
            }
        }
        return count;
        
    }
};
