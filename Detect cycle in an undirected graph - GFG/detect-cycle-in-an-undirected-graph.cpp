//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i,int p,vector<int> g[], vector<int> &v){
        v[i]=1;
        for(auto x: g[i]){
            if(!v[x]) {
                if(dfs(x,i,g,v)) return 1;
            }
            else if(x!=p) return 1;
        }
        return 0;
    }
    bool isCycle(int n, vector<int> g[]) {
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            if(!v[i]) if(dfs(i,-1,g,v)) return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends