class Solution {
    void generateParenthesis(int n,int open,int close, vector<char> temp, vector<string> &ans){
        
        if(open>n || close>n)return;
        if(open==n && close==n){
            string t="";
            for(auto it:temp)t+=it;
            
            ans.push_back(t);
            return;
        }
        
        temp.push_back('(');
        generateParenthesis(n,open+1,close,temp,ans);
        temp.pop_back();
        if(open>close){
            temp.push_back(')');
            generateParenthesis(n,open,close+1,temp,ans);
            temp.pop_back();
        }
         
        
    }
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string > ans;
        vector<char> temp;
        generateParenthesis(n,0,0,temp,ans);
        return ans;
    }
};