class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a1="";
        string a2="";
        
        for(auto i:word1)a1+=i;
        for(auto i:word2)a2+=i;
        
        if(a1.size()!=a2.size())return false;
        
        int n=a1.size();
        for(int i=0;i<n;i++)
            if(a1[i]!=a2[i])return false;
        
        return true;
    }
};