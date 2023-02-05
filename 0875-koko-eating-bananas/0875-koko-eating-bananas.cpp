class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int e=*max_element(begin(p),end(p));
        while(l<=e){
            int m=l+(e-l)/2;
            if(c(p,h,m)) {
                e=m-1;
            }
            else l=m+1;
        }
        return l;
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