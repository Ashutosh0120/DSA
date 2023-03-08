class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int e=1e9;
        int ans=0;
        while(l<=e){
            int m=l+(e-l)/2;
            if(c(p,h,m)) {
                e=m-1;
                ans=m;
            }
            else l=m+1;
        }
        return ans;
    }
    bool c(vector<int>&p,int h,int m){
        long ans=0;
        for(auto x: p){
            ans+=(x/m);
            if(x%m!=0) ans+=1;
        }
        return ans<=h;
    }
};