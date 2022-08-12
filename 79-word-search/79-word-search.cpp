class Solution {
    //TC-O(n*m*(4^k)) k is the length of string
    bool exist(int m,int n,int r,int c,vector<vector<char> > &board,int ptr, string word,vector<vector<int> > &visited) {
        
        if(word[ptr]=='\0')return true;
        
        if(r<0 ||r>=m ||c<0 || c>=n || word[ptr]!=board[r][c] || visited[r][c]!=-1)return false;
        
        visited[r][c]=0;
        bool t= (exist(m,n,r+1,c,board,ptr+1,word,visited)|| 
                 exist(m,n,r-1,c,board,ptr+1,word,visited)|| 
                 exist(m,n,r,c+1,board,ptr+1,word,visited)|| 
                 exist(m,n,r,c-1,board,ptr+1,word,visited) );
        
        visited[r][c]=-1;
        return t;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int> > visited(m,vector<int>(n,-1));
        
        //find start positiom
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(exist(m,n,i,j,board,0,word,visited))
                    return true;
            }
        }
        return false;
    }
};