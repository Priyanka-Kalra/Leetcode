class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>  answer;
        unordered_map<string,vector<string> > mp;
        
        
        for(auto it: paths){
            stringstream s(it);  
            //location
            string location,file_name,file_text;
            getline(s,location,' ');
            
            while(s){
                getline(s,file_name,'(');
                getline(s,file_text,')');
                
                if(s.str().size()!=1){
                    string t;
                    getline(s,t,' ');
                }
                string temp=location+'/'+file_name;
                mp[file_text].push_back(temp);
            }
        }
        
        for(auto it:mp)if(it.second.size()>1)answer.push_back(it.second);
        
        return answer;
        
    }
};