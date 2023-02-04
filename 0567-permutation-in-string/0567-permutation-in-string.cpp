class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(begin(s1),end(s1));
        if(s1.size()>s2.size()) return false;
        int n=size(s1),m=size(s2);
        for(int i=0;i<m-n+1;i++){
            string f=s2.substr(i,n);
            sort(begin(f),end(f));
            if(f==s1) return true;
        }
        return false;
    }
};