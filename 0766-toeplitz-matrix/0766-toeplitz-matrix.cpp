//TC-O(N*M)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        int el,i,j,k;
        
        //left to right first col
        for(i=0;i<n;i++){
            el=matrix[0][i];
            k=i+1;
            for(j=1;j<m&& k<n;j++){
                if(matrix[j][k]!=el)return false;
                k++;
            }
        }
        
        //top to down first row
        for(i=1;i<m;i++){
            el=matrix[i][0];
            k=i+1;
            for(j=1;j<n&& k<m;j++){
                if(matrix[k][j]!=el)return false;
                k++;
            }
        }
        
        return true;
    }
};
