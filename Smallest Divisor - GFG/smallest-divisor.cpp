//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& v, int k) {
        int l=1, h=1e9;
        int ans=0;
        int n=v.size();
        while(l<=h){
            int mi=l+(h-l)/2;
            int c=0;
            for(int i=0;i<n;i++){
                c+=(v[i]/mi);
                if(v[i]%mi!=0)c++;
            }
            if(c<=k){
                ans=mi;
                h=mi-1;
            }
            else l=mi+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends