//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   
    int f(int i, int j, int n, int m,int p,vector<vector<int>>&g,vector<vector<int>> &dp){
        if(i<0 or j<0 or i==n or j==m) return 0;
        if(p>=g[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        p=g[i][j];
        int a=f(i+1,j,n,m,p,g,dp);
        int b=f(i-1,j,n,m,p,g,dp);
        int c=f(i,j+1,n,m,p,g,dp);
        int d=f(i,j-1,n,m,p,g,dp);
        return dp[i][j]=1+max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int mx=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r=f(i,j,n,m,-1,g,dp);
                mx=max(mx,r);
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends