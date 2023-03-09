class Solution {
public:
    void k(string s, int n, vector<string> &v, int o, int c){
        if(o==n and c==n) {
            v.push_back(s);return;
        } 
        if(o<n) k(s+"(",n,v,o+1,c);
        if(c<o) k(s+")",n,v,o,c+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        k("",n,v,0,0);
        return v;
    }
};