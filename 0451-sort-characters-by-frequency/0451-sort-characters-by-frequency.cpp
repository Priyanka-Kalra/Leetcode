class Solution {
public:
    string frequencySort(string s) {
        
        if(s.size()==1)return s;
        
        unordered_map<char,int> mp;
        priority_queue<pair<int,char> > pq;
        
        for(auto i:s)mp[i]++;
        
        for(auto i:mp)pq.push({i.second,i.first});
        
        s="";
        while(!pq.empty()){
            pair<int,char> t=pq.top();
            pq.pop();
            s+=string(t.first,t.second);//first variable denotes number of times and second denotes the variable
            
        }
        
        return s;
    }
};