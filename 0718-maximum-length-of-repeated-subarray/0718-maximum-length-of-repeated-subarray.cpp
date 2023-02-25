class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int n1=size(v1), n2=size(v2);
        int r=0;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(v1[i-1]==v2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    r=max(r,dp[i][j]);
                }
            }
        }
        return r;
    }
};