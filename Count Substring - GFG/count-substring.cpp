//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int ans=0;
        map<char,int> m;
        int n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            while(m['a'] and m['b'] and m['c']) {
                ans+=(n-i);
                m[s[l++]]--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends