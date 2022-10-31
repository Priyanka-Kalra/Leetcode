//TC-O(N*M)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        //left to right first col
        for(int i=0;i<n;i++){
            int el=matrix[0][i];
            int k=i+1;
            for(int j=1;j<m&& k<n;j++){
                if(matrix[j][k]!=el)return false;
                k++;
            }
        }
        
        //top to down first row
        for(int i=1;i<m;i++){
            int el=matrix[i][0];
            int k=i+1;
            for(int j=1;j<n&& k<m;j++){
                if(matrix[k][j]!=el)return false;
                k++;
            }
        }
        
        return true;
    }
};
