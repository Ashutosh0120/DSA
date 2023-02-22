class Solution {
public:
    bool c(int m,vector<int>&w, int d){
        int cp=0,p=0;
        int n=size(w);
        for(auto x: w){
            if(cp+x<=m) cp+=x;
            else{
                cp=x;
                p++;
            }
        }
        p++;
        return (p<=d);
    }
    int shipWithinDays(vector<int>& w, int d) {
        int b=*max_element(begin(w),end(w));
        int e=accumulate(begin(w),end(w),0);
        while(b<=e){
            int m=b+(e-b)/2;
            if(c(m,w,d)) e=m-1;
            else b=m+1;
        }
        return b;
    }
};