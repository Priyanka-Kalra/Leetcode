//https://leetcode.com/problems/permutation-in-string/discuss/1762469/C%2B%2B-oror-SLIDING-WINDOW-OPTIMIZED-oror-Well-Explained
class Solution {
    bool areEqual(vector<int> &a,vector<int> &b){
        
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;

        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())return false;
        
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        for(char i:s1)freq1[i-'a']++;
        
        int i=0,j=0;
        while(j<s2.size()){
            
            freq2[s2[j]-'a']++;
            
            if(j-i+1==s1.size() && areEqual(freq1,freq2))return true;
            else if(j-i+1<s1.size())j++;
            else{
                freq2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        
        return false;
    }
};