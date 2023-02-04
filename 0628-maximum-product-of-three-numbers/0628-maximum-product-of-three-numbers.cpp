class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=size(nums);
        sort(begin(nums),end(nums));
        int ans=max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        return ans;
    }
};