//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{   
public:
    char decodeIt(string s, int k)
    {
    	string f = "";
    	for (int i = 0; i < s.size(); i++) {
    		if (s[i] >= 'a' and s[i] <= 'z') {
    			f += s[i];
    		}
    		else {
    		    string t=f;
    			int r = s[i] - '0';
    			for (int i = 0; i < r - 1; i++) {
    				f+=t;
    			}
    		}
    	}
    	return f[k-1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int k;
        cin>>k;
        Solution ob;
        cout << ob.decodeIt(str,k) << endl;
    }
}
// } Driver Code Ends