//https://leetcode.com/problems/simplify-path/discuss/1847357/C%2B%2B-oror-Easy-oror-Stack-oror-Simple-oror-Explained-oror-Algorithm
class Solution {
public:
    //TC-O(N)
    //SC-O(N)
    string simplifyPath(string path) {
        
        stack<string> order;
        for(int i=0;path[i]!='\0';){
            
            if(path[i]=='/'){
                i++;
                continue;
            }
            string temp="";
            while(path[i]!='\0' &&path[i]!='/'){
                temp+=path[i];
                i++;
            }
            
            
            if(temp==".."){
                if(order.size()>0)order.pop();
            }
            else if(temp==".")continue;
            else order.push(temp); 
        }
        
        string ans="";
        if(order.size()==0){
            ans+='/';
            return ans;
        }
        
        while(!order.empty()){
            ans='/'+order.top()+ans;
            order.pop();
        }
        
        return ans;
    }
};