//https://www.youtube.com/watch?v=jSto0O4AJbM
class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()<t.size()){
            string ans="";
            return ans;
        }
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto it:t){
            mp1[it]++;//for string t,need
            mp2[it]=0;
        }
        
        pair<int,int> p={-1,INT_MAX};//index,length
        
        int need=t.size(),have=0;
        int i=0,j=0;
        while(s[j]!='\0'){
            
            
            if(mp2.find(s[j])!=mp2.end() ){
                if(mp2[s[j]]<mp1[s[j]])have++;
                mp2[s[j]]++;
            }
            
            while(need==have){
                int d=j-i;
                if(d<=p.second){
                    p.second=d;
                    p.first=i;
                }
                if(mp2.find(s[i])!=mp2.end() && mp2[s[i]]>0){
                    mp2[s[i]]--;
                    
                    if(mp2[s[i]]<mp1[s[i]])have--;
                }
                i++;
            }
            j++;
            
        }
        
        int si=p.first;
        int ei=p.first+p.second;
        string ans="";
        if(si==-1)return ans;
        for(int i=si;i<=ei;i++)ans+=s[i];
        
        return ans;
    }
};