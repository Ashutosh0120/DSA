//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& f, int b, int e, int k)  {
        vector<pair<int,int>> adj[n];
        for(auto x: f) adj[x[0]].push_back({x[1],x[2]});
        vector<int> d(n,1e9);
        queue<pair<int,pair<int,int>>> p;
        d[b]=0;
        p.push({0,{b,0}});
        while(!p.empty()){
            auto x=p.front(); p.pop();
            int s=x.first;
            int c=x.second.first, w=x.second.second;
            if(s>k) continue;
            for(auto a: adj[c]){
                int nc=a.first,w1=a.second;
                if(w1+w<d[nc] and s<=k){
                    d[nc]=w1+w;
                    p.push({s+1,{nc,d[nc]}});
                }
            }
        }
        if(d[e]==1e9) return -1;
        return d[e];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends