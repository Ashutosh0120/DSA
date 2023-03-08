//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(int start, int k, int n,vector<int> &ds,vector<vector<int>> &ans){
        if(k<0 or n<0) return;
        if(k==0 and n==0){
            ans.push_back(ds);
            return;
        }
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            f(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        f(1,k,n,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends