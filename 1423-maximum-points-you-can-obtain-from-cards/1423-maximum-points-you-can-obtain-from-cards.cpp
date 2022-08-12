class Solution {
public:
    //TC-O(K),SC-O(1)
    
    //https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/2337113/O(k)-Time-complexity-Simple-solution-with-handwritten-explanation.
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int right_sum=0,left_sum=0;
        
        //sum of right k elements
        for(int i=0;i<k;i++)
            right_sum+=cardPoints[n-1-i];
        
        //
        int max_score=right_sum;
        for(int i=0;i<k;i++){
            left_sum+=cardPoints[i];
            right_sum-=cardPoints[n-k+i];
            
            max_score=max(max_score,left_sum+right_sum);
        }
        
        return max_score;
    }
};
