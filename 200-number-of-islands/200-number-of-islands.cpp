//TC-O(8*(N^2))
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