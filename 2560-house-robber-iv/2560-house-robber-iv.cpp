class Solution {
public:
    bool run(vector<int> &nums, int k, int m){
        int i=0, n=size(nums);
        while(i<n){
            if(nums[i]<=m){
                i+=2;
                k--;
            }
            else i++;
            if(k==0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(begin(nums),end(nums)), r=*max_element(begin(nums),end(nums));
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(run(nums,k,m)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};