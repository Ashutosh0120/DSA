class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,h=0;
        int ans=0;
        map<int,int> m;
        while(h<s.size()){
            m[s[h]]++;
            while(m[s[h]]>1){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,h-l+1);
            h++;
        }
        return ans;
    }
};