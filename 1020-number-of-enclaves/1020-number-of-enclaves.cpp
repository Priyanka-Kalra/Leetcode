class Solution {
    
    void dfs(int i,int j,int r,int c,vector< vector<int> > & board,vector< vector<int> > & visited){
        
        visited[i][j]=1;
        
        if(i+1<r && board[i+1][j]==1 && visited[i+1][j]==0)
            dfs(i+1,j,r,c,board,visited);
        if(i-1>=0 && board[i-1][j]==1 && visited[i-1][j]==0)
            dfs(i-1,j,r,c,board,visited);
        if(j+1<c && board[i][j+1]==1 && visited[i][j+1]==0)
            dfs(i,j+1,r,c,board,visited);
        if(j-1>=0 && board[i][j-1]==1 && visited[i][j-1]==0)
            dfs(i,j-1,r,c,board,visited);
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        vector< vector<int> > visited(r, vector<int>(c,0));
        
        for(int i=0;i<r;i++)
            if(visited[i][0]==0 && grid[i][0]==1)dfs(i,0,r,c,grid,visited);
        for(int i=0;i<r;i++)
            if(visited[i][c-1]==0 && grid[i][c-1]==1)dfs(i,c-1,r,c,grid,visited);
        for(int i=0;i<c;i++)
            if(visited[0][i]==0 && grid[0][i]==1)dfs(0,i,r,c,grid,visited);
        for(int i=0;i<c;i++)
            if(visited[r-1][i]==0 && grid[r-1][i]==1)dfs(r-1,i,r,c,grid,visited);
        
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visited[i][j]==0 && grid[i][j]==1)ans++;  
            }
        }
        return ans;
        
    }
};