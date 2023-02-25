//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                if(!st.empty()){
                    ans+=c;
                }
                
                st.push(c);
            }
            else {
                st.pop();
                if(!st.empty()){
                    ans+=c;
                }
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