//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int k, vector<int> &v){
        if((m*k)>(v.size())) return -1;
        int n=v.size();
        int l=1, h=1e9;
        int ans=-1;
        while(l<=h){
            int mi=l+(h-l)/2;
            int p=0,c=0;
            for(int i=0;i<n;i++){
                if(v[i]<=mi) c++;
                else c=0;
                if(c==k) {
                    c=0;
                    p++;
                }
            }
            if(p>=m){
                ans=mi; h=mi-1;
            }
            else l=mi+1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends