//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int c(int m,vector<int> &v,int h){
        int c=0;
        //  int n=size(v);
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            c+=(v[i]/m);
            if((v[i]%m)!=0) c++;
        }
        return (c<=h);
    }
    int Solve(int n, vector<int>& v, int h) {
        // int n=size(v);
        int b=1, e=*max_element(begin(v),end(v));
        int ans=-1;
        while(b<=e){
            int m=b+(e-b)/2;
            if(c(m,v,h)){
                ans=m;
                e=m-1;
            }
            else {
                b=m+1;
            }
        }
        return ans;
        // Code here
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