//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i, int j, int n, int m,int p,vector<vector<int>>& g,vector<vector<int>> &dp){
        if(i<0 or j<0 or i>=n or j>=m or p>=g[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        p=g[i][j];
        int a=f(i+1,j,n,m,p,g,dp);
        int b=f(i-1,j,n,m,p,g,dp);
        int c=f(i,j+1,n,m,p,g,dp);
        int d=f(i,j-1,n,m,p,g,dp);
        return dp[i][j]=1+max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& g, int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx=max(mx,f(i,j,n,m,-1,g,dp));
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends