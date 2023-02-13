class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0,n=size(nums);
        int i=0,j=n-1;
        while(i<j){
            ans+=(nums[j--]-nums[i++]);
        }
        return ans;
    }
};