class Solution {
public:
    
    //3.edge case like ab ab.  and abab. abab
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size())return false;
        
        int n=s.size();
        
        int p1=-1,p2=-1;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                if(p1==-1)p1=i;
                else if(p2==-1)p2=i;
                else return false;
            }
            
        }
        
        //abc  cba
        if(p1!=-1 && p2!=-1){
            if(s[p1]!=goal[p2] || s[p2]!=goal[p1])return false;
            else return true;
        }
        //abc.  adc
        else if(p1!=-1 && p2==-1)return false;
        
        //ab ab.  abab abab
        unordered_set<char> mp;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(mp.find(c)!=mp.end())return true;
            
            mp.insert(c);
        }
        return false;
    }
};