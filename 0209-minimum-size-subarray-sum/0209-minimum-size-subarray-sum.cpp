class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int l=0, r=0, n=size(v)-1;
        long long s=0;
        long long k=accumulate(begin(v),end(v),0LL);
        if(k<t) return 0;
        int ans=1e5;
        while(r<=n){
            s+=v[r];
            while(s>=t){
                ans=min(ans,r-l+1);
                s-=v[l++];
            }
            r++;
        }
        return ans;
    }
};