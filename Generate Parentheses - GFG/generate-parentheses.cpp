//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void h(vector<string> &v, string s, int n, int o,int c){
        if(o==n and c==n){
            v.push_back(s);
            return;
        }
        if(o<n) h(v,s+'(',n,o+1,c);
        if(c<o) h(v,s+')',n,o,c+1);
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;
        int o=0, c=0;
        h(v,"",n, o, c);
        return v;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends