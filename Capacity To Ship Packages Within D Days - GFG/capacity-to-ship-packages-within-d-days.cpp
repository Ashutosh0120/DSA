//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int c(int arr[], int m, int d,int n){
        int p=0,md=0;
        for(int i=0;i<n;i++){
            if(md+arr[i]<=m){
                md+=arr[i];
            }
            else{
                md=arr[i];
                p++;
            }
        }
        p++;
        return (p<=d);
    }
    int leastWeightCapacity(int arr[], int n, int d) {

        int b=*max_element(arr,arr+n);
        int e=accumulate(arr,arr+n,0);
        
        while(b<=e){
            int m=b+(e-b)/2;
            if(c(arr,m,d,n)){
                e=m-1;
            }
            else b=m+1;
        }
        return b;
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