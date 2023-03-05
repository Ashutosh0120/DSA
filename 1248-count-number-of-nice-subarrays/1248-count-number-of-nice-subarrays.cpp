class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=size(nums);
        for(int i=0;i<n;i++){
            if(nums[i]&1) nums[i]=1;
            else nums[i]=0;
        }
        int c=0;
        int r=0;
        
        map<int,int> m;
        for(int i=0;i<n;i++){
            c+=nums[i];
            if(c==k) r++;
            if(m.find(c-k)!=m.end()){
                r+=m[c-k];
            }
            m[c]++;
        }
        return r;
    }
};