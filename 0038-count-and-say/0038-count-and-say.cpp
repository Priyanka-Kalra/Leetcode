class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)return "1";
        
        string temp=countAndSay(n-1);
        int size=temp.size();
        string ans="";
        int count=1;
        for(int i=1;i<size;i++){
            if(temp[i]!=temp[i-1]){
                ans+=to_string(count)+temp[i-1];
                count=1;
            }
            else
                count++;
        }
        ans+=to_string(count)+temp[size-1];
        return ans;
        
    }
};