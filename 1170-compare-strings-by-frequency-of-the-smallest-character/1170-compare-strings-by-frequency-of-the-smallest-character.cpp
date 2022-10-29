class Solution {
    int freq(string s){
        vector<int> f(26,0);
        
        for(int i=0;s[i]!='\0';i++)f[s[i]-'a']++;
        
        for(int i=0;i<26;i++)
            if(f[i]!=0)return f[i];
        
        return 0;
    }
    
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> answer;
        vector<int> fr(12,0);
        //storing count of strings with a given frequency.here max frequency is 10
        
        for(int i=0;i<words.size();i++){
            int f=freq(words[i]);
            fr[f]++;
        }
        
        //cumulative
        for(int i=9;i>=0;i--)fr[i]+=fr[i+1];
        
        for(int i=0;i<queries.size();i++){
            int f=freq(queries[i]);
            answer.push_back(fr[f+1]);
        }
        
        return answer;
    }
};