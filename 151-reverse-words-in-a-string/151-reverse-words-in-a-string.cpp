class Solution {
public:
    string reverseWords(string s) {
        
        int i=0;
        int n=s.size();
        stack<string> order;
        while(i<n){
            
            if(s[i]==' '){
                i++;
                continue;
            }
            
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            order.push(temp);
        }
        
        string ans="";
        while(!order.empty()){
            if(order.size()==1){
                ans+=order.top();
                order.pop();
            }
            else{
                ans+=order.top()+' ';
                order.pop();
            }
            
        }
        
        return ans;
    }
};