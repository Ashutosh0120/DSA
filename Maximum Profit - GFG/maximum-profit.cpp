//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int b,int k,int n,int a[],vector<vector<vector<int>>> &dp){
        if(i==n or k==0) return 0;
        if(dp[i][b][k]!=-1) return dp[i][b][k];
        int c=0;
        if(b==0){
            c=max(f(i+1,0,k,n,a,dp),-a[i]+f(i+1,1,k,n,a,dp));
        }
        else{
            c=max(f(i+1,1,k,n,a,dp),a[i]+f(i+1,0,k-1,n,a,dp));
        }
        return dp[i][b][k]=c;
    }
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,0,k,n,a,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends