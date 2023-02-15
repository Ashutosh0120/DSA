class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mi=nums[0], mx=nums[0],ans=nums[0];
        int n=size(nums);
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0) swap(mi,mx);
            mi=min(nums[i],mi*(nums[i]));
            mx=max(nums[i],mx*(nums[i]));
            ans=max(ans,mx);
        }
        return ans;
    }
};