//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<int>> &v,vector<vector<char>> &g)
    {
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size()) return ;
        if(v[i][j] or g[i][j]=='X') return ;
        v[i][j]=1;
        dfs(i+1,j,v,g);dfs(i-1,j,v,g);dfs(i,j+1,v,g);dfs(i,j-1,v,g);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> g)
    {
        vector<vector<int>> v(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(!v[i][0] and g[i][0]=='O') dfs(i,0,v,g);
            if(!v[i][m-1] and g[i][m-1]=='O') dfs(i,m-1,v,g);
        }
        for(int j=0;j<m;j++){
            if(!v[0][j] and g[0][j]=='O') dfs(0,j,v,g);
            if(!v[n-1][j] and g[n-1][j]=='O') dfs(n-1,j,v,g);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] and g[i][j]=='O') g[i][j]='X';
            }
        }
        return g;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends