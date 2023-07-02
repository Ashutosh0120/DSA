//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int n=s.size();
        int i=0,j=0;
        int mx=0;
        int m[26]={};
        while(j<n){
            m[s[j]-'a']++;
            while(m[s[j]-'a']>1){
                m[s[i]-'a']--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
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
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends