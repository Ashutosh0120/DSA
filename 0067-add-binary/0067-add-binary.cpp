class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int s=0,c=0;
        while(i>=0 or j>=0){
            s=c;
            if(i>=0) s+=(a[i--]-'0');
            if(j>=0) s+=(b[j--]-'0');
            ans+=to_string(s%2);
            c=s/2;
        }
        if(c!=0) ans+='1';
        reverse(begin(ans),end(ans));
        return ans;
    }
};