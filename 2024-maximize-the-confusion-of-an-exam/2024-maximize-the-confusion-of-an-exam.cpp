class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        map<char,int> m;
        int l=0, mx=0, a=0;
        int n=size(s);
        for(int r=0;r<n;r++){
            m[s[r]]++;
            mx=max(mx,m[s[r]]);
            if((r-l+1-mx)>k){
                m[s[l]]--; l++;
            }
            else a=max(a,r-l+1);
        }
        return a;
    }
};