class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int b=1,e=1e6;
        int ans=0;
        int n=size(nums);
        while(b<=e){
            int m=b+(e-b)/2;
            int s=0;
            for(int i=0;i<n;i++){
                if(nums[i]%m==0) s+=(nums[i]/m);
                else s+=(nums[i]/m)+1;
            }
            if(s<=threshold) {
                ans=m;
                e=m-1;
            }
            else {
                b=m+1;
            }
        }
        return ans;
    }
};