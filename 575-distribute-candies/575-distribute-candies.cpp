class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int n=candyType.size();
        
        unordered_set<int> mp;
        for(auto it: candyType)
            mp.insert(it);
        
        
        int count=(int)mp.size();
        if(count<n/2)return count;
        else return n/2;
    }
};