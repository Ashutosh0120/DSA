class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=size(nums);
        vector<int> s(n), p(n);
        p[0]=1;
        s[n-1]=1;
        for(int i=1;i<n;i++){
            p[i]=p[i-1]*nums[i-1];  
        }
        for(int i=n-2;i>=0;i--){
            s[i]=s[i+1]*nums[i+1];  
        }
        for(int i=0;i<n;i++){
            nums[i]=s[i]*p[i];
        }
        return nums;
    }
};