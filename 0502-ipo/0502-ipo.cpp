#define pi pair<int,int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int a=w,n=size(p);
        priority_queue<int> pq;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) 
            v[i]={c[i],p[i]};
        sort(begin(v),end(v));
        int i=0;
        while(k--){
            while(i<n and v[i].first<=a){
                pq.push(v[i].second); i++;
            }
            if(pq.size()==0) return a;
            a+=pq.top();
            pq.pop();
        }
        return a;
    }
};