class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=size(nums), s=0;
        m[0]=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(!m.count(s%k)) m[s%k]=i+1;
            if(m[s%k]<i) return true;
        }
        return false;
    }
};