class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0, j=0;
        int n=size(nums);
        int mx=INT_MIN;
        int p=0;
        while(j<n){
            while(nums[j]&p){
                p=p^nums[i];
                i++;
            }
            p=p|(nums[j]);
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};