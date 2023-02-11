class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(begin(nums),end(nums));
        int ans=0;
        int d=nums[0]+nums[1]+nums[2];
        int n=size(nums);
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(abs(s-t)<abs(d-t)){
                    d=s;
                }
                if(s<t) l++;
                else r--;
            }
        }
        return d;
    }
};