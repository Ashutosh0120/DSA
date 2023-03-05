//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int l=0, r=0;
        map<char,int> m;
        int n=s.size();
        int c=0;
        int ans=0;
        while(r<n)
        {
            m[s[r]]++;
            c=max(c,m[s[r]]);
            if((r-l+1-c)>k){
                m[s[l]]--;
                l++;
            }
            else{
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends