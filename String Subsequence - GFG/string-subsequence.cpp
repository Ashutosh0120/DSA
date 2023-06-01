//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int j,int n,int m,string a, string b,vector<vector<int>> &dp){
        if(j==m) return 1;
        if(i==n) return 0;
        int t=0;
        if(a[i]==b[j]){
            t=f(i+1,j+1,n,m,a,b,dp);
        }
        int nt=f(i+1,j,n,m,a,b,dp);
        return t+nt;
    }
    int countWays(string a, string b){
        // code here
        int n=a.size(), m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,n,m,a,b,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends