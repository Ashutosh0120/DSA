class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int> sh(26,0),ph(26,0),ans;
        int n=size(s),m=size(p);
        for(int i=0;i<m;i++){
            sh[s[i]-'a']++;
            ph[p[i]-'a']++;
        }
        if(sh==ph) ans.push_back(0);
        
        for(int i=m;i<n;i++){
            sh[s[i]-'a']++; sh[s[i-m]-'a']--;
            if(sh==ph) ans.push_back(i-m+1);   
        }
        return ans;
    }
};