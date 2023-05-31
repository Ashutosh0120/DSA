//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int f(int i,string a, set<string> &s){
        if(i==a.size()) return 1;
        string t="";
        for(int j=i;j<a.size();j++){
            t+=a[j];
            if(s.find(t)!=s.end()){
                if(f(j+1,a,s)) return 1;
            }
        }
        return 0;
    }
    int wordBreak(string a, vector<string> &v) {
        //code here
        set<string> s(v.begin(),v.end());
        return f(0,a,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends