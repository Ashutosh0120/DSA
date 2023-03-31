//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int> d(n,1e9);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        d[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            int w=pq.top().first;
            int r=pq.top().second;
            pq.pop();
            for(auto x: adj[r]){
                int e=x[1];
                int p=x[0];
                if(w+e<d[p]){
                    d[p]=w+e;
                    pq.push({d[p],p});
                }
            }
        }
        return d;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends