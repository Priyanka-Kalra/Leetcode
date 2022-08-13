class Solution {
    //TC-O(2^N)
    //SC-O(K)
    void combine(int si,int n, int k,vector<int> &temp,vector<vector<int>> &output){
        
        if(k==0){
            output.push_back(temp);
            return;
        }
        if(si>n)return;
        
        for(int i=si;i<=n;i++){
            temp.push_back(i);
            combine(i+1,n,k-1,temp,output);
            temp.pop_back();
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        vector<vector<int>> output;
        combine(1,n,k,temp,output);
        return output;
    }
};
