//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU {
    std::vector<int> parent;
    std::vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
    int getSize(int x) {
        int root = find(x);
        return size[root];
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& v) {
        DSU d(n);
        if(v.size()<(n-1)) return -1;
        int c=0;
        for(auto x: v){
            if(d.find(x[0])==d.find(x[1])) c++;
            else d.merge(x[0],x[1]);
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(d.find(i)==i) nc++;
        }
        return (c>=(nc-1))?(nc-1):-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends