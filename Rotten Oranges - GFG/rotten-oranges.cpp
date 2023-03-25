//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m]={};
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) {
                    c1++;
                }
            }
        }
        int time=0;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first, c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nr=dr[i]+r, nc=dc[i]+c;
                if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0 and grid[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    c2++;
                }
            }
        }
        return (c1==c2)?time:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends