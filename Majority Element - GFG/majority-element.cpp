//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        int e=0,c=0;
        for(int i=0;i<n;i++){
            if(c==0){
                e=a[i];
            }
            if(e==a[i]) c++;
            else c--;
        }
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==e){
                r++;
            }
        }
        return (r>(n/2))?e:-1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends