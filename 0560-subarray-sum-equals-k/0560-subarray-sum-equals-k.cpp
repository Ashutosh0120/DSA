class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int c=0,s=0,n=size(nums);
        for(int i=0;i<n;i++){
            s+=nums[i];
            c+=(s==k);
            c+=(m.find(s-k)!=m.end())?m[s-k]:0;
            m[s]++;
        }
        return c;
    }
};