//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int m, vector<int>&v, int k){
        int a=0;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            a+=(v[i]/m);
            if(v[i]%m!=0) a++; 
        }
        return a<=k;
    }
    int Solve(int n, vector<int>& v, int k) {
        // Code here
        int l=1, h=1e9;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,v,k)) {
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends