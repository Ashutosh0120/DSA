class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=size(nums);
        map<int,int> m;
        int s=0, c=0;
        for(auto &x:nums){
            if(x&1) x=1;
            else x=0;
        }
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s==k) c++;
            if(m.find(s-k)!=m.end()) c+=m[s-k];
            
            m[s]++;
        }
        return c;
    }
};