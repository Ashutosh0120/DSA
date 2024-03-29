//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src){
        vector<int> adj[n];
        for(auto it: edges)
        {   
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis(n,1e9);
        dis[src]=0;
        queue<int> q;q.push(src);
        while(!q.empty()){
            int r=q.front(); q.pop();
            for(auto x: adj[r]){
                if(dis[r]+1<dis[x]){
                    dis[x]=dis[r]+1;
                    q.push(x);
                }
            }
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(dis[i]!=1e9) ans[i]=dis[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends