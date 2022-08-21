class Solution {
    int count(int r,int c,int m,int n,vector<vector<int> > &dp){
        
        if(r==m-1&& c==n-1)return dp[r][c]=1;
        if(r<0 ||c<0||r==m||c==n)return 0;
        
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]=(count(r+1,c,m,n,dp)+count(r,c+1,m,n,dp));
        
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return count(0,0,m,n,dp);
    }
};