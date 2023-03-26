//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dr[4]={1,0,-1,0},dc[4]={0,-1,0,1};

    void dfs(int r, int c, vector<vector<int>> &v,vector<vector<char>>& mat){
        v[r][c]=1;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(nr>=0 and nr<n and nc>=0 and nc<m and !v[nr][nc] and mat[nr][nc]=='O'){
                dfs(nr,nc,v,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!v[0][j] and mat[0][j]=='O'){
                dfs(0,j,v,mat);
            }
            if(!v[n-1][j] and mat[n-1][j]=='O'){
                dfs(n-1,j,v,mat);
            }
        }
        for(int i=0;i<n;i++){
            if(!v[i][0] and mat[i][0]=='O'){
                dfs(i,0,v,mat);
            }
            if(!v[i][m-1] and mat[i][m-1]=='O'){
                dfs(i,m-1,v,mat);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
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