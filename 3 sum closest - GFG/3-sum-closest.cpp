//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int x)
    {
        // code here
        sort(nums,nums+n);
        int s=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1, r=n-1;
            while(l<r){
                int d=nums[i]+nums[l]+nums[r];
                if(abs(d-x)<abs(s-x)) s=d;
                if(d<x) l++;
                else r--;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends