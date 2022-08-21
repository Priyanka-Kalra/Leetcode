//1.Recursion,TC-O(2^(n*m)) ,SC-O(m+n-2)
//2.Memoization,TC-O(m*n)  ,SC-O(m+n-2)+O(m*n)
/*
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
*/
//dp
class Solution {

public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[0][0]=1;
                else{
                    int left=(i>0)?dp[i-1][j]:0;
                    int right=(j>0)?dp[i][j-1]:0;
                    dp[i][j]=left+right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};