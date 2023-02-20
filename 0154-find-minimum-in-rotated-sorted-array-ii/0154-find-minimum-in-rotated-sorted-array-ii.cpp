class Solution {
public:
    int findMin(vector<int>& nums) {
        int b=0,e=size(nums)-1;
        while(b<e){
            int m=(b+e)/2;
            if(nums[m]>nums[e]) b=m+1;
            else if(nums[m]<nums[e]) e=m;
            else e--;
        }
        return nums[b];
    }
};