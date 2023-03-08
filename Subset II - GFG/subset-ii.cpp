//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void f(int i,vector<vector<int>> &d,vector<int> &k,vector<int>& v, int n)
    {
            d.push_back(k);
            for(int j=i;j<n;j++){
                if(j>i and v[j]==v[j-1]) continue;
                k.push_back(v[j]);
                f(j+1,d,k,v,n);
                k.pop_back();
            }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& v) {
        // Write your code here
        sort(v.begin(),v.end());
        vector<vector<int>> d;
        vector<int> k;
        int n=v.size();
        f(0,d,k,v,n);
        return d;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends