//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &a) {
        // code here
        vector<int> v;
        stack<int> s;
        for(int i=0;i<n;i++){
            if(a[i]>0) s.push(a[i]);
            else{
                bool t=true;
                while(!s.empty()){
                    if(s.top()<0) break;
                    else if(s.top()<abs(a[i])) s.pop();
                    else if(s.top()==abs(a[i])){
                        t=!t;
                        s.pop(); break;
                    }
                    else {
                        t=!t; break;
                    }
                }
                if(t) s.push(a[i]);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(begin(v),end(v));
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends