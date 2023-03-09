class Solution {
public:
    int h(vector<int> &s, int k){
        int n=size(s); int c=0;
        map<int,int> m;
        int b=0,e=0;
        while(e<n){
            m[s[e]]++;
            while(m.size()>k){
                m[s[b]]--;
                if(m[s[b]]==0)
                    m.erase(s[b]);
                b++;
            }
            c+=(e-b+1);
            e++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& s, int k) {
        return h(s,k)-h(s,k-1);
    }
};