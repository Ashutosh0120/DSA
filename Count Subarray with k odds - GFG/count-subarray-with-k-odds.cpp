//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        for(int i=0;i<n;i++) {
            nums[i]=(nums[i]&1)?1:0;
        }
        int c=0;
        int r=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            c+=nums[i];
            if(c==k) r++;
            if(m.find(c-k)!=m.end()){
                r+=m[c-k];
            }
            m[c]++;
        }
        return r;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends