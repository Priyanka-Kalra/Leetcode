class Solution {
    //tc-O(n*n*logn)
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        unordered_map< int,vector<int> > mp;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[j-i].push_back(mat[i][j]);
            }
        }
        
        for( unordered_map< int,vector<int> > :: iterator it=mp.begin();it!=mp.end();it++){
            
            sort(it->second.begin(),it->second.end());
        }
        
        //last diag
        for(int i=0;i<n;i++){
            int r=m-1;
            int c=i;
            int key=c-r;
            vector<int>temp=mp[key];
            int ind=temp.size()-1;
            
            while(ind>=0){
                mat[r][c]=temp[ind];
                r--;
                c--;
                ind--;
            }
        }
        //last col
        for(int i=m-2;i>=0;i--){
            int r=i;
            int c=n-1;
            int key=c-r;
            vector<int>temp=mp[key];
            int ind=temp.size()-1;
            
            while(ind>=0){
                mat[r][c]=temp[ind];
                r--;
                c--;
                ind--;
            }
        }
        return mat;
    }
};