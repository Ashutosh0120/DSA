//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topo(int i, vector<pair<int,int>>adj[],int v[],stack<int>&s){
        v[i]=1;
        for(auto x: adj[i]){
            int a=x.first;
            if(!v[a]) topo(a,adj,v,s);
        }
        s.push(i);   
    }
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            auto x=edges[i];
            int u=x[0], v=x[1], d=x[2];
            adj[u].push_back({v,d});
        }
        int v[n]={0};
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!v[i]){
                topo(i,adj,v,s);
            }
        }
        vector<int> d(n,1e9);
        d[0]=0;
        while(!s.empty()){
            int r=s.top(); s.pop();
            for(auto x: adj[r]){
                int v=x.first, p=x.second;
                if(d[r]+p<d[v]){
                    d[v]=d[r]+p;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(d[i]==1e9){
                d[i]=-1;
            }
        }
        return d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends