//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<int> adj[],int v[],int p[]){
        v[i]=1;
        p[i]=1;
        
        for(auto x: adj[i]){
            if(!v[x]){
                if(dfs(x,adj,v,p)) return 1;
            }
            else if(v[x] and p[x]){
                return 1;
            }
        }
        p[i]=0;
        return 0;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        int v[n]={0};
        int p[n]={0};
        for(int i=0;i<n;i++){
            if(!v[i]){
                if(dfs(i,adj,v,p)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends