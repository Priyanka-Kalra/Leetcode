class Solution {
    int Num_words(string s){
        int count=0;
        for(int i=0;s[i]!='\0';i++)
            if(s[i]==' ')count++;
        
        return count+1;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        unordered_map<string,int> mp;
        int n=messages.size();
        
        for(int i=0;i<n;i++){
            int num=Num_words(messages[i]);
            mp[senders[i]]+=num;
        }
        
        string ans;
        int max=-1;
        for(auto i:mp){
            if(i.second>max){
                ans=i.first;
                max=i.second;
            }
            else if(i.second==max && i.first>ans)ans=i.first;
        }
        return ans;
    }
};