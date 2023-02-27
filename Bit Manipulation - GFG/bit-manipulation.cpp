//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int n, int i) {
        // your code here
        int r=(1<<(i-1));
        int r1=(n>>(i-1))&1;
        int r2=(n|((1<<(i-1))));
        int r3=(n&~(r));
        cout<<r1<<' '<<r2<<" "<<r3;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends