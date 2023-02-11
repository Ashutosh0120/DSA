class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            if(i==0 or (nums[i]!=nums[i-1] and i>0)){
                int l=i+1, h=n-1;
                int s=-nums[i];
                while(l<h){
                    if(nums[l]+nums[h]==s) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[l]);
                        v.push_back(nums[h]);
                        ans.push_back(v);
                        while(l<h and nums[l]==nums[l+1]) l++;
                        while(l<h and nums[h]==nums[h-1]) h--;
                        l++; h--;
                    }
                    else if(nums[l]+nums[h]<s) l++;
                    else h--;
                }
            }
        }
        return ans;
    }
};