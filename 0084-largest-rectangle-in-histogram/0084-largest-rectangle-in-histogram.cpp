class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=size(v);
        stack<int> s;
        int l[n], r[n];
        for(int i=0;i<n;i++){
            while(!s.empty() and v[s.top()]>=v[i]){
                s.pop();
            }
            l[i]=(s.empty())?0:s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and v[s.top()]>=v[i]){
                s.pop();
            }
            r[i]=(s.empty())?n-1:s.top()-1;
            s.push(i);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,v[i]*(r[i]-l[i]+1));
        }
        return mx;
    }
};