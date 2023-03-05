class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx=INT_MIN;
        int l=0, r=0;
        int n=size(nums);
        int z=0;
        while(r<n){
            if(nums[r]==0) z++;
            while(z>k){
                if(nums[l]==0) z--;
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};