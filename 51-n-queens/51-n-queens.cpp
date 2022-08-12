class Solution {
    
    void solveNQueens(int n,vector<string> &board,vector<vector<string>> &TOTAL,vector<int> &Left,vector<int> &Ldiag,vector<int> &Udiag,int col){
        
        if(col==n){
            TOTAL.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            
            if(Left[row]==-1 &&Ldiag[row+col]==-1 && Udiag[n-1 +col- row]==-1){
                
                Left[row]=1;
                Ldiag[row+col]=1;
                Udiag[n-1 +col- row]=1;
                board[row][col]='Q';
                solveNQueens(n,board,TOTAL,Left,Ldiag,Udiag,col+1);
                board[row][col]='.';
                Left[row]=-1;
                Ldiag[row+col]=-1;
                Udiag[n-1 +col- row]=-1;
            }
            
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<int> Left(n,-1);
        vector<int> Ldiag(2*n-1,-1);
        vector<int> Udiag(2*n-1,-1);
        
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        vector<vector<string>> TOTAL;
        solveNQueens(n,board,TOTAL,Left,Ldiag,Udiag,0);
        return TOTAL;
    }
};