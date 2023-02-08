class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0,n=size(nums);
        
        for(int i=0;i<n;i++){
            if(mx<i) return false;
            mx=max(mx,nums[i]+i);
        }
        return true;
    }
};