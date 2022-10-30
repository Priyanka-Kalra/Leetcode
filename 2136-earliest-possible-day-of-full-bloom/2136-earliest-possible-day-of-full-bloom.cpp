//https://www.youtube.com/watch?v=rlvmHB1cCxc&t=454s
class Solution {
    static bool sortcol(const vector<int> &v1,const vector<int> &v2){
        return v1[1]>v2[1];
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n=plantTime.size();
        
        vector<vector<int> > t(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            t[i][0]=plantTime[i];
            t[i][1]=growTime[i];
        }
        
        //decreasing order
        sort(t.begin(),t.end(),sortcol);
        
        int ans=0,prev_day=0;
        for(int i=0;i<n;i++){
            int plant_t=t[i][0];
            int grow_t=t[i][1];
            
            ans=max(ans,prev_day+plant_t+grow_t);
            prev_day+=plant_t;
        }
        return ans;
    }
};