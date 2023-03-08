class Solution {
public:
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void s(string di, int i, int n, string o, vector<string>&d){
        if(i==n){
            d.push_back(o); 
            return;
        }
        for(auto x: v[di[i]-'0']){
            o.push_back(x);
            s(di,i+1,n,o,d);
            o.pop_back();
        }
    }
    vector<string> letterCombinations(string di) {
        vector<string> d;
        int n=size(di);
        if(n==0) {
            return d;
        }
        s(di,0,n,"",d);
        return d;
    }
};