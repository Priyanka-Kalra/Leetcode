//TC-O(N*K) k is avg length of string,n is number of strings
class Solution {
    int freq(string s){
        vector<int> f(26,0);
        
        for(auto i:s)f[i-'a']++;
        
        for(int i=0;i<26;i++)
            if(f[i]!=0)return f[i];
        
        return 0;
    }
    
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> answer;
        
        //index from 0 to 11,11 index required bcz if in line 35,assume f=10
        vector<int> fr(12,0);
        
        //storing count of strings with a given frequency.here max frequency is 10
        
        int n=words.size();
        for(int i=0;i<n;i++){
            int f=freq(words[i]);
            fr[f]++;
        }
        
        //cumulative
        for(int i=9;i>=0;i--)fr[i]+=fr[i+1];
        
        n=queries.size();
        for(int i=0;i<n;i++){
            int f=freq(queries[i]);
            answer.push_back(fr[f+1]);
        }
        
        return answer;
    }
};