//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int b=1,e=30;
	    while(b<=e){
	        int mi=(b+e)/2;
	        double ans=pow(mi,n);
	        if(ans==m) return mi;
	        else if(ans<m) b=mi+1;
	        else e=mi-1;
	    }
	    return -1;
	    
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends