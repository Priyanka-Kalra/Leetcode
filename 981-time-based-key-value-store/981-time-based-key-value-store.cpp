class TimeMap {
    //key,(time,value)
    unordered_map<string, unordered_map< int,string > > mp;
public:
    //n is avg length of key and value
    //t=timestamp
    
    //O(n) for each call
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    //O(t.n) for each call
    string get(string key, int timestamp) {
        
        if(mp.count(key)==0)return "";
        for(int i=timestamp;i>=1;i--){
            if(mp[key].count(i)!=0)return mp[key][i];
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */