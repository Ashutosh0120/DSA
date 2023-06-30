//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        int n=s.size();
        stack<char>t;
        string ans="";
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                if(!t.empty()) ans+=c;
                t.push(c);
                // ans+=c;
            }
            else if(c==')'){
                t.pop();
                if(!t.empty()) ans+=c;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends