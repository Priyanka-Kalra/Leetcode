class Solution {
    bool validPalindrome(string s,int si,int ei,int count){
        if(count>1)return false;
        
        while(si<ei){
            if(s[si]==s[ei]){
                si++;
                ei--;
            }
            else{
                return (validPalindrome(s,si+1,ei,count+1) || validPalindrome(s,si,ei-1,count+1));
            }
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int n=s.size();
        
        return validPalindrome(s,0,n-1,0);
    }
};