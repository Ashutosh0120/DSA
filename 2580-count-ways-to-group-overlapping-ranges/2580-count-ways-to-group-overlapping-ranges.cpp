class Solution {
public:
    int fastpow(int i, int j, int k) {
        if (j == 1) return i;
        if (j == 0) return 1;
        long long ans = fastpow(i, j / 2, k);
        ans = (ans * ans) % k;
        if (j % 2 == 1) ans = (ans * i) % k;
        return ans;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(begin(ranges),end(ranges));
        vector<int> v=ranges[0];
        int r=0;
        for(int i=1;i<ranges.size();i++){
            int p=v[1];
            int c=ranges[i][0];
            if(c<=p){
                v[1]=max(v[1],ranges[i][1]);
            }
            else{
                r++;
                v=ranges[i];
            }
        }
        r++;
        return fastpow(2,r,1e9+7);
    }
};