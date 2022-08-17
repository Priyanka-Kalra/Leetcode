class Solution {
    void dfs(int row,int col,vector<vector<char>>& grid,vector< vector<int>>& visited){
        
        int m=grid.size();
        int n=grid[0].size();
        visited[row][col]=0;
        
        if(row+1<m && grid[row+1][col]=='1' && visited[row+1][col]==-1)
            dfs(row+1,col,grid,visited);
        if(row-1>=0 && grid[row-1][col]=='1' && visited[row-1][col]==-1)
            dfs(row-1,col,grid,visited);
        if(col+1<n && grid[row][col+1]=='1' && visited[row][col+1]==-1)
            dfs(row,col+1,grid,visited);
        if(col-1>=0 && grid[row][col-1]=='1' && visited[row][col-1]==-1)
            dfs(row,col-1,grid,visited);
            
        
        
        // queue<pair<int,int> > order;
        // order.push({row,col});
        
//         while(!order.empty()){
//             int r=order.front().first;
//             int c=order.front().second;
//             order.pop();
//             visited[r][c]=0;
            
//             for(int i=-1;i<=1;i++){
//                 for(int j=-1;j<=1;j++){
                    
//                     int tr=r+i;
//                     int tc=c+j;
                    
//                     if(tr!=r && tc!=c)continue;
                    
//                     if(tr>=0 && tr<m && tc>=0 &&tc<n){
//                         if(grid[tr][tc]=='1' && visited[tr][tc]==-1)
//                             order.push({tr,tc});
//                     }
//                 }
//             }
//         }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
    
        
        int count=0;
        vector< vector<int>> visited(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==-1){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};