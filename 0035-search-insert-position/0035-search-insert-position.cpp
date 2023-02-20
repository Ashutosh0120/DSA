class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b=0,e=size(nums)-1;
        int ans=-1;
        while(b<=e){
            int m=(b+e)/2;
            if(nums[m]<target) b++;
            else e--;
        }
        return b;
    }
};