//https://www.youtube.com/watch?v=V5r7PQhcJCQ
//1.Brute force,TC-O(N^2)
//2.if nums[i]>stack.top(), we push <stack.top,nums[i]> in map and pop from stack.this will continue till nums[i]<=stack.top(),then we will insert nums[i] in stack 
class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        stack<int> st;
        st.push(nums2[0]);
        unordered_map<int,int> mp;
        for(int i=1;i<n;i++){
            
            while(!st.empty() && st.top()<nums2[i]){
                int t=st.top();
                st.pop();
                mp[t]=nums2[i];
            }
            st.push(nums2[i]);   
        }
        
        
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            if(mp.find(nums1[i])!=mp.end()){
                ans[i]=mp[nums1[i]];
            }
        }
        return ans;
    }
};