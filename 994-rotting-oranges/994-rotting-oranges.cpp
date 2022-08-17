class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        queue< pair< pair<int,int>,int> > q;//<<row,col>,time>
        
        
        int i,j;
        int count1=0;
        int count2=0;
        
        //starting points
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1 )
                    count1++;
                else if(grid[i][j]==2 ){
                    count2++;
                    visit[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        //edge case
        if(count1==0)return 0;
        if(count2==0)return -1;
        
        
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            
            if(r+1<m && grid[r+1][c]==1 && visit[r+1][c]==0){
                visit[r+1][c]=2;
                grid[r+1][c]=2;
                q.push({{r+1,c},t+1});
            }
            
            if(r-1>=0 && grid[r-1][c]==1&& visit[r-1][c]==0){
                visit[r-1][c]=2;
                grid[r-1][c]=2;
                q.push({{r-1,c},t+1});
            }
                
            if(c+1<n && grid[r][c+1]==1&& visit[r][c+1]==0){
                visit[r][c+1]=2;
                grid[r][c+1]=2;
                q.push({{r,c+1},t+1});
            }
                
            if(c-1>=0 && grid[r][c-1]==1&& visit[r][c-1]==0){
                visit[r][c-1]=2;
                grid[r][c-1]=2;
                q.push({{r,c-1},t+1});
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1 ){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};
