//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int ans=0;
        unordered_map<int,int> m;
        int s=0;
        m[0]=-1;
        for(int i=0;i<n;i++){
            s+=a[i];
            if (m.find(s-k)!=m.end()){
                ans=max(ans,i-m[s-k]);
            }
            if(m.find(s)==m.end()) m[s]=i;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends