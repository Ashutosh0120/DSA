class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long s=0;
        int n=size(nums);
        for(int i=0;i<n;i++){
            long long mx=-1e9, mi=1e9;
            for(int j=i;j<n;j++){
                if(mx<nums[j]) mx=nums[j];
                if(mi>nums[j]) mi=nums[j];
                s+=(mx-mi);
            }
        }
        return s;
    }
};