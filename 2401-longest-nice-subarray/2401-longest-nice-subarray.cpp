class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=0;
        int ans=0;
        int j=0;
        int i=0;
        while(i<size(nums)){
            while((nums[i]&n)) {
                n^=nums[j];
                j++;
            }
            n|=nums[i];
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};