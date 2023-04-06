//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define pii pair<int,pair<int,int>>
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;  //priority_queue
        int n=h.size(), m=h[0].size(); //l,b
        vector<vector<int>> d(n,vector<int>(m,1e9));//dis
        // TC= 0(N*M*4*LOG(N*M))
        d[0][0]=0; //start
        pq.push({0,{0,0}});  //start pos inside the dis
        int dr[]={1,0,-1,0}, dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            int w=p.first;
            int x=p.second.first, y=p.second.second;
            if(x==n-1 and y==m-1) return w;
            for(int i=0;i<4;i++){
                int nr=dr[i]+x;
                int nc=dc[i]+y;
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    int nd=max(w,abs(h[nr][nc]-h[x][y]));
                    if(nd<d[nr][nc]){
                        d[nr][nc]=nd;
                        pq.push({nd,{nr,nc}});
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