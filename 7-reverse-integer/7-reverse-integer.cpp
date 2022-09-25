class Solution {
public:
    int reverse(int x) {
        
        bool negative=x<0?1:0;
        
        x=abs(x);
        long invert=0;
        while(x>0){
            invert=invert*10+x%10;
            x/=10;
        }
        
        if(negative)invert*=-1;
        
        if(invert>INT_MAX || invert<INT_MIN)return 0;
        return invert;
    }
};