//https://www.youtube.com/watch?v=y-PoFX6oCAg
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        long long sum=0;
        int max_val=milestones[0];
        for(auto i:milestones){
            sum+=i;
            max_val=max(max_val,i);
        }
        sum-=max_val;
        
        long long ans;
        if(sum<=max_val-1)ans=2*sum +1;
        else ans=sum+max_val;
        
        return ans;
    }
};