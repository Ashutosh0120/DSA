//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> topo(vector<int> adj[], int n){
        vector<int> in(n,0);
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                in[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        vector<int> p;
        while(!q.empty())
        {
            int r=q.front(); q.pop();
            p.push_back(r);
            for(auto x: adj[r]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }
        return p;
    }
    string findOrder(string dict[], int n, int k) {
        string a="";
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int l=min(s1.size(),s2.size());
            for(int j=0;j<l;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> v=topo(adj,k);
        for(auto x: v){
            a+=(x+'a');
        }
        return a;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends