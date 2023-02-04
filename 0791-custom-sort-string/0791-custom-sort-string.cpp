class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        string ans="";
        for(auto x: s) m[x]++;
        int n=size(order),p=size(s);
        for(int i=0;i<n;i++){
            while(m[order[i]]>0){
                ans+=order[i];
                m[order[i]]--;
            }
        }
        for(auto x: m){
            while(x.second>0){
                ans+=x.first; x.second--;
            }
        }
        return ans;
    }
};