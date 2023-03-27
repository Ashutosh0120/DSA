//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>& g,vector<vector<int>>&v,vector<pair<int,int>> &p,int i1,int j1){
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or v[i][j] or g[i][j]!=1) return;
        if()
        v[i][j]=1;
        p.push_back({i-i1,j-j1});
        dfs(i+1,j,g,v,p,i1,j1);
        dfs(i-1,j,g,v,p,i1,j1);
        dfs(i,j+1,g,v,p,i1,j1);
        dfs(i,j-1,g,v,p,i1,j1);
    }
    int countDistinctIslands(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        // int v[n][m]={0};
        vector<vector<int>>v(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] and g[i][j]==1){
                    vector<pair<int,int>> p;
                    dfs(i,j,g,v,p,i,j);
                    st.insert(p); 
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends