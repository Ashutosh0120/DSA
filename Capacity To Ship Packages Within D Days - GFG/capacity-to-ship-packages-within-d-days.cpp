//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int b=*max_element(arr,arr+n);
        int e=accumulate(arr,arr+n,0);
        int ans=-1;
        while(b<=e){
            int m=(b+e)/2;
            int bo=1,p=0;
            for(int i=0;i<n;i++){
                if(arr[i]+p<=m){
                    p+=arr[i];
                }
                else{
                    bo++;
                    p=arr[i];
                }
            }
            if(bo<=d){
                ans=m; e=m-1;
            }
            else b=m+1;
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