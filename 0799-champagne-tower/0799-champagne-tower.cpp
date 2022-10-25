//https://www.youtube.com/watch?v=PbdeSn67Kfs
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double> > glass (102,vector<double> (102,0));
        glass[0][0]=poured;
        
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){

                if(glass[i][j]>1.0){
                    double remaining=glass[i][j]-1.0;
                    glass[i+1][j]+=remaining/2.0;
                    glass[i+1][j+1]+=remaining/2.0;
                }
            }
        }
        
        double ans=1.0;
        if(glass[query_row][query_glass]<ans)ans=glass[query_row][query_glass];
        return ans;
    }
};