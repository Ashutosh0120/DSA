//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& v, int k) {
        // Code here
        vector<int> ans;
        map<int,int> m;
        for(auto x: v) m[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        for(auto x: m){
            p.push({x.second,x.first});
            if(p.size()>k) p.pop();
        }
        
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends