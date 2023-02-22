//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& v1, vector<int>& v2)
    {
        if(v2.size()<v1.size()) return MedianOfArrays(v2,v1);
        int n1=v1.size();
        int n2=v2.size();
        int l=0,e=n1;
        while(l<=e){
            int c1=(l+e)/2;
            int c2=(n1+n2+1)/2-c1;
            int l1=(c1==0)?INT_MIN:v1[c1-1];
            int l2=(c2==0)?INT_MIN:v2[c2-1];
            int r1=(c1==n1)?INT_MAX:v1[c1];
            int r2=(c2==n2)?INT_MAX:v2[c2];
            if(l1<=r2 and l2<=r1){
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2) e=c1-1;
            else l=c1+1;
        }
        return 0.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends