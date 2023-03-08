//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void f(int i, int s, int n, vector<int> &d, vector<int> &v){
        if(i==n){
            v.push_back(s);
            return;
        }
        f(i+1,s+d[i],n,d,v);
        f(i+1,s,n,d,v);
    }
    vector<int> subsetSums(vector<int> d, int n)
    {
        // Write Your Code here
        vector<int> v;
        int i=0, s=0;
        f(i,s,n,d,v);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends