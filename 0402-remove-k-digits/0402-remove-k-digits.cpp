class Solution {
public:
    string removeKdigits(string num, int k) {
        string a="";
        int n=num.size(),t=(n-k);
        for(auto x: num){
            while(k and a.size() and a.back()>x){
                a.pop_back();
                k--;
            }
            a.push_back(x);
        }
        a.resize(t);
        while(!a.empty() and a[0]=='0') a.erase(begin(a));
        return (a.empty())?"0":a;
    }
};