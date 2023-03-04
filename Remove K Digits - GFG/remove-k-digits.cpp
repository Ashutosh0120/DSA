//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        string a="";
        int r=(s.size()-k);
        for(auto x: s){
            while(k and a.back()>x and a.size()){
                a.pop_back();
                k--;
            }
            a.push_back(x);
        }
        a.resize(r);
        while(a.size() and a[0]=='0') a.erase(begin(a));
        return (a.empty())?"0":a;
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
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends