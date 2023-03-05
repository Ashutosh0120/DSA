class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        map<char,int> m;
        int n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            while(m['a'] and m['b'] and m['c']) {
                ans+=(n-i);
                m[s[l++]]--;
            }
        }
        return ans;
    }
};