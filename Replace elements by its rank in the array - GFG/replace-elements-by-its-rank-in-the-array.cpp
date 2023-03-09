//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &v, int n){
        vector<int> a(v.begin(),v.end());
        sort(a.begin(),a.end());
        int c=1;
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(a[i])==m.end()) {
                m[a[i]]=c++;
                continue;
            }
        }
        for(int i=0;i<n;i++){
            v[i]=m[v[i]];
        }
        return v;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends