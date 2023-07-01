//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool f(string a, string b){
        if(a.size()!=b.size()) return 0;
        map<char,char> m;
        for(int i=0;i<a.size();i++){
            if(m.find(a[i])==m.end()) m[a[i]]=b[i];
            else {
                if(m[a[i]]!=b[i]) return 0;
            }
        }
        return 1;
    }
    bool areIsomorphic(string a, string b)
    {
        return f(a,b) and f(b,a);   
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends