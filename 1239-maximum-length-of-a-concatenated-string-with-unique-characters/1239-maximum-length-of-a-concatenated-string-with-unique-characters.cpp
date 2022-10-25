//using backtracking form different subsequences. for each subsequence check whether all characters unique or not(if unique update the answer)
class Solution {
    bool isunique(string s){
        
        vector<int> freq(26,0); 
        for(int i=0;s[i]!='\0';i++){
            if(freq[s[i]-'a']==1)return false;
            else freq[s[i]-'a']++;
        }
        return true;
    }
    void maxLength(int ind,int n,vector<string>& arr,string cur_string,int &ans){
        
        if(!isunique(cur_string))return;
        ans=max(ans, (int)cur_string.size());
        if(ind==n)return;
        
        
        maxLength(ind+1,n,arr,cur_string+arr[ind],ans);
        maxLength(ind+1,n,arr,cur_string,ans);
        
    }
    
public:
    int maxLength(vector<string>& arr) {
        
        int ans=0;
        maxLength(0,arr.size(),arr,"",ans);
        return ans;
    }
};