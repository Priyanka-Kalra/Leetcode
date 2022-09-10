//https://www.youtube.com/watch?v=BtdgAys4yMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=15
//we start with with border elements=='O' and mark the elements connected to  such elements.
//finally we traverse completely on board and for those position it has not been maeked/visited we put 'X'
class Solution {
    
    void dfs(int i,int j, int r,int c,vector<vector<char>>& board,vector<vector<int>> &visited){
        
        visited[i][j]=1;
        
        if(i+1<r && visited[i+1][j]==0 && board[i+1][j]=='O')
            dfs(i+1,j,r,c,board,visited);
        if(j+1<c && visited[i][j+1]==0 && board[i][j+1]=='O')
            dfs(i,j+1,r,c,board,visited);
        if(i-1>0 && visited[i-1][j]==0 && board[i-1][j]=='O')
            dfs(i-1,j,r,c,board,visited);
        if(j-1>0 && visited[i][j-1]==0 && board[i][j-1]=='O')
            dfs(i,j-1,r,c,board,visited);
        
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int r=board.size();
        int c=board[0].size();
        
        vector<vector<int>> visited(r,vector<int> (c,0));
        
        for(int i=0;i<r;i++){
            if(board[i][0]=='O' && visited[i][0]==0)
                dfs(i,0,r,c,board,visited);
        }
        for(int i=0;i<r;i++){
            if(board[i][c-1]=='O' && visited[i][c-1]==0)
                dfs(i,c-1,r,c,board,visited);
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O' && visited[0][i]==0)
                dfs(0,i,r,c,board,visited);
        }
        for(int i=0;i<c;i++){
            if(board[r-1][i]=='O' && visited[r-1][i]==0)
                dfs(r-1,i,r,c,board,visited);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visited[i][j]==0)board[i][j]='X';
            }
        }
        
    }
};