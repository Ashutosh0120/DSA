class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        int n=size(nums);
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                long long s1=(long long)target-(nums[i]+nums[j]);
                int l=j+1, h=n-1;
                while(l<h){
                    long long s2=nums[l]+nums[h];
                    if(s2==s1){
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                        while(l<n-1 and nums[l]==nums[l+1])l++;
                        while(h>0 and nums[h]==nums[h-1])h--;
                        l++; h--;
                    }
                    else if(s2>s1) h--;
                    else l++;
                }
            }
        }
        return ans;
    }
};