class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int n=size(nums);
        int s=0,c=0;
        map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            int r=(s%k);
            if(r<0) r+=k;
            if(m.find(r)!=m.end()) c+=m[r];
            m[r]++;
        }
        return c;
    }
};