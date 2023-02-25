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
    bool c(string a, string b){
        map<char,char> m;
        int n=a.size();
        if(a.size()!=b.size()){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(m.find(a[i])!=m.end()){
                if(m[a[i]]!=b[i]) return 0;
            }
            else{
                m[a[i]]=b[i];
            }
        }
        return 1;
    }
    bool areIsomorphic(string a, string b)
    {
        return c(a,b) and c(b,a);
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