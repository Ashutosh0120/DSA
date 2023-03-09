class Solution {
public:
    void k(int i, vector<vector<string>>&v,vector<string>&c,string s){
        if(i==s.size()) {
            v.push_back(c);
            return;
        }
        
        for(int j=i;j<s.size();j++){
            if(p(s,i,j)){
                c.push_back(s.substr(i,j-i+1));
                k(j+1,v,c,s);
                c.pop_back();
            }
        }
    }
    bool p(string s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string> c;
        k(0,v,c,s);
        return v;
    }
};