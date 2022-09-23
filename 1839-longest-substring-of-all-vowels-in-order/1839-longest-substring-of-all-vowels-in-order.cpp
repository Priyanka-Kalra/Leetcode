class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int n=word.size();
        if(n<5)return 0;
        
        int cur_length=1;
        int max_length=0;
        int count=1;
        
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1])cur_length++;
            else if(word[i]>word[i-1]){
                cur_length++;
                count++;
            }
            else {
                count=1;
                cur_length=1;
            }
            
            if(count==5)max_length=max(max_length,cur_length);
            
        }
        
        return max_length;
    }
};