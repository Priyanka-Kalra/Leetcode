//TC-O(N*k)N is size of strs,K is avg length of each string
//SC-O(N)

/*
1.Maintain a map with key(of map) as string type and value(of map) as vector<string>. this means "unordered_map<string,vector<string> >mp;"
2.store each string as temp and then sort each string(s).store temp with key as s.this means "mp[s].push_back(temp)"
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string> >mp;
        for(auto s:strs){
            
            string temp=s;
            sort(s.begin(),s.end());
            mp[s].push_back(temp);
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};