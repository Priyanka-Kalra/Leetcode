class Solution {
public:
    bool isValid(string s) {
        
        stack<char> order;
        for(int i=0;s[i]!='\0';i++){
            char c=s[i];
            if(c=='(' || c=='{' || c=='[')order.push(c);
            
            else if(c==')' ){
                if(!order.empty() && order.top()=='(')order.pop();
                else return false;
            }
            else if(c=='}' ){
                if(!order.empty() && order.top()=='{')order.pop();
                else return false;
            }
            else if(c==']' ){
                if(!order.empty() && order.top()=='[')order.pop();
                else return false;
            }
        }
        
        if(!order.empty())return false;
        else return true;
    }
};