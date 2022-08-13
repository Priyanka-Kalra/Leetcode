class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> mp;
        for(auto it:nums){
            if(mp.find(it)!=mp.end())
                return true;
            else
                mp.insert(it);
        }
        return false;
    }
};