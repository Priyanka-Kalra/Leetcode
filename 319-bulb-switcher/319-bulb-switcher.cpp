//https://www.youtube.com/watch?v=7IbWTFOUP1U&t=401s
class Solution {
    //if starting from off(base) condition, then only those bulbs will be on which will be toggled odd times.
    //only those will be toggled odd times,that have odd factors i.e perfect square numbers. for eg if n=20 then bulbs 1,4,9,16 will be on. correspong sqrt are 1,2,3,4
    //TC-O(N^0.5),SC-O(1)
public:
    int bulbSwitch(int n) {
        
        int i=1;
        int ans=0;
        while(i*i<=n){
            ans++;
            i++;
        }
        return ans;
        
    }
};