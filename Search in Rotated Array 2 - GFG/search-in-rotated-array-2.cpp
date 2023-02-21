//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& v, int x) {
        // Code here
        int b=0, e=n-1;
        while(b<=e){
            int m=(b+e)/2;
            if(v[m]==x) return 1;
            if(v[m]==v[b] and v[m]==v[e]) {
                b++;
                e--;
            }
            if(v[b]<=v[m]){
                if(v[b]<=x and x<=v[m]){
                    e=m-1;
                }
                else b=m+1;
            }
            else{
                if(v[m]<=x and x<=v[e]){
                    b=m+1;
                }
                else e=m-1;
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
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends