//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int n, int t){
        // code here
        map<int,int> m;
        int r=0;
        int c=0;
        for(int i=0;i<n;i++){
            c+=arr[i];
            if(c==t) r++;
            if(m.find(c-t)!=m.end()){
                r+=m[c-t];
            }
            m[c]++;
        }
        return r;
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
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends