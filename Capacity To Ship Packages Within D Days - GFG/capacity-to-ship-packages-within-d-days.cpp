//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int v[], int n, int d) {
        // code here
        int l=*max_element(v,v+n);
        int h=accumulate(v,v+n,0);
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            int s=0, c=1;
            for(int i=0;i<n;i++){
                if(s+v[i]<=m) s+=v[i];
                else{
                    s=v[i];
                    c++;
                }
            }
            if(c<=d) {
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends