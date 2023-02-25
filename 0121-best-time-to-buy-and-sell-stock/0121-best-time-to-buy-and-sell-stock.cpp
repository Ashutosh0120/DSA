class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0, mi=1e4;
        int n=size(prices);
        for(int i=0;i<n;i++){
            int mi=min(mi,prices[i]);
            mx=max(mx,prices[i]-mi);
        }
        return mx;
    }
};