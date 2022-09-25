class Solution {
public:
    int reverse(int x) {
        
        bool negative=x<0?1:0;
        
        int Y=abs(x);
        long invert=0;
        while(Y>0){
            invert=invert*10+Y%10;
            Y/=10;
        }
        
        if(negative)invert*=-1;
        
        if(invert>INT_MAX || invert<INT_MIN)return 0;
        return invert;
    }
};