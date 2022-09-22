//1.reverse the stringand put each word in stack. then pop from stack and put each word in final answer
//2.Reverse word by word
class Solution {
    void swap(char &a, char &b){
        char c=a;
        a=b;
        b=c;
    }
    void reverse(string &s,int si,int ei){
        while(si<ei){
            swap(s[si],s[ei]);
            si++;
            ei--;
        }
    }
public:
    string reverseWords(string s) {
        int n=s.size();
        if(n==1)return s;
        
        int prev=0;
        for(int i=1;i<n;i++){
            
            if(s[i]==' '){
                reverse(s,prev,i-1);
                prev=i+1;
            }
        }
        reverse(s,prev,n-1);
        return s;
    }
};