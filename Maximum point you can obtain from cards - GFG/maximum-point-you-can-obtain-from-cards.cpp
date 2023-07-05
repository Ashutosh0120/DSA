//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &v, int n, int k) {
        // code here
        long long s=0,m=0;
        int j=0;
        int p=k;
        while(k--){
            s+=v[j++];
        }
        j--;
        m=max(m,s);
        for(int i=n-1;i>=0 and p--;i--){
            s-=v[j--];
            s+=v[i];
            m=max(m,s);
        }
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends