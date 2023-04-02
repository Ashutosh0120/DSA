//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,pair<int,int>>
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        priority_queue<pii,vector<pii>,greater<pii>> p; 
        int n=h.size(), m=h[0].size();
        
        vector<vector<int>> d(n,vector<int>(m,1e9));
        d[0][0]=0;
        p.push({0,{0,0}});
        int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
        while(!p.empty()){
            auto x=p.top();
            p.pop();
            int di=x.first;
            int r=x.second.first, c=x.second.second;
            if(r==n-1 and c==m-1){
                return di;
            }
            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 and nc>=0 and nr<n and nc<m){
                    int ne=max(abs(h[r][c]-h[nr][nc]),di);
                    if(ne<(d[nr][nc])){
                       d[nr][nc]=ne;
                       p.push({ne,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends