class Solution {
public:
    long long c(long long m, vector<int> &t, int tt)
    {
        long long k=0;
        for(int i=0;i<t.size();i++){
            k+=((long long)(m/t[i]));
        }
        return k>=tt;
    }
    long long minimumTime(vector<int>& t, int tt) {
        sort(begin(t),end(t));
        long long ans=0;
        long long l=1;
        long long h=1e14;
        while(l<=h){
            long long m=l+(h-l)/2;
            if(c(m,t,tt)){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};