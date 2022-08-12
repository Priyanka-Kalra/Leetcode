class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        if(n==2)return (min(height[0],height[1]));
        
        int maxQuantity=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            
            int h=min(height[i],height[j]);
            maxQuantity=max(maxQuantity,h*(j-i));
            
            if(height[i]<height[j])i++;
            else j--;
        }
        
        return maxQuantity;
    }
};