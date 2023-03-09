class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=size(nums);
        return nums[n-k];
    }
};