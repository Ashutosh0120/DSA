class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int c=0;
        int n=size(nums);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        c+=((nums[i]+nums[j]+nums[k])==nums[l]);
                    }
                }
            }
        }
        return c;
    }
};