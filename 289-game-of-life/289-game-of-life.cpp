class Solution {
    
    //https://www.youtube.com/watch?v=fei4bJQdBUQ
    
    //TC-O(8*M*N)
    bool checkLive(int i,int j,vector<vector<int>>& board,int m,int n){
        
        int count=0;
        //previous row
        if(i-1>=0){
            if(j-1>=0 && (board[i-1][j-1]==1 || board[i-1][j-1]==3) )count++;
            if(j+1<n && (board[i-1][j+1]==1 || board[i-1][j+1]==3) )count++;
            if(board[i-1][j]==1 || board[i-1][j]==3)count++;
            
        }
        
        //next row
        if(i+1<m){
            if(j-1>=0 && (board[i+1][j-1]==1 || board[i+1][j-1]==3) )count++;
            if(j+1<n && (board[i+1][j+1]==1 || board[i+1][j+1]==3) )count++;
            if(board[i+1][j]==1 || board[i+1][j]==3)count++;
        }
        
        //current row
        if(j-1>=0 && (board[i][j-1]==1 || board[i][j-1]==3) )count++;
        if(j+1<n && (board[i][j+1]==1 || board[i][j+1]==3) )count++;
        
        if(board[i][j]==1 &&(count==2 || count==3))return true;
        else if(board[i][j]==0 && count==3)return true;
        else return false;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int t=board[i][j];
                
                if(t==0){
                    if(checkLive(i,j,board,m,n))
                        board[i][j]=2;
                }
                else if(t==1){
                    if(checkLive(i,j,board,m,n))
                        board[i][j]=3;
                    else
                        board[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==0)board[i][j]=0;
                else if(board[i][j]==1 )board[i][j]=0;
                else if(board[i][j]==2 )board[i][j]=1;
                else if(board[i][j]==3 )board[i][j]=1;
                
            }

        }

    }
};