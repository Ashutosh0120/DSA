//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int b=0,e=0;
        map<char,int> m;
        int n=s.size();
        int mx=0,a=0;
        while(e<n){
            m[s[e]]++;
            mx=max(mx,m[s[e]]);
            while((e-b+1-mx)>k){
                m[s[b]]--;
                if(m[s[b]]==0)m.erase(s[b]);
                b++;
            }
            a=max(a,e-b+1);
            e++;
        }
        return a;
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