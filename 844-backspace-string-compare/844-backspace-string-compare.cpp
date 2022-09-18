class Solution {
    string final(string s){
        
        int n=s.size();
        stack<char> st;
        
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else if(st.size()>0)
                st.pop();
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        
        string s1=final(s);
        string s2=final(t);
        
        
        return s1==s2;
    }
};