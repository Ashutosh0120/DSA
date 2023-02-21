class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int f=0;
        for(auto x: nums){
            f=f^x;
        }
        return f;
    }
};