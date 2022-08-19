class Solution {
    //https://www.youtube.com/watch?v=edXdVwkYHF8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=14
    //instead of starting from 1(initial) we start from each 0(target)
    
    //TC-O(N*M)
    //SC-O(N*M)
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        queue< pair<pair<int,int >,int > > q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visit[i][j]=true;
                }
            }
        }
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            
            ans[r][c]=dis;
            
            if(r+1<m && visit[r+1][c]==false){
                visit[r+1][c]=true;
                q.push({{r+1,c},dis+1});
            }
            if(r-1>=0 && visit[r-1][c]==false){
                visit[r-1][c]=true;
                q.push({{r-1,c},dis+1});
            }
            if(c+1<n && visit[r][c+1]==false){
                visit[r][c+1]=true;
                q.push({{r,c+1},dis+1});
            }
            if(c-1>=0 && visit[r][c-1]==false){
                visit[r][c-1]=true;
                q.push({{r,c-1},dis+1});
            }
        }
        
        return ans;
    }
};