class Solution {
public:
    bool h(int i,int r, int c,vector<vector<char>>& b, string &w){
        if(i==w.size()) return 1;
        if(r<0 or c<0 or r==b.size() or c==b[0].size() or w[i]!=b[r][c]) return 0;
        char t=b[r][c];
        b[r][c]='*';
        bool f=(h(i+1,r+1,c,b,w) or h(i+1,r-1,c,b,w) or h(i+1,r,c+1,b,w) or h(i+1,r,c-1,b,w));
        b[r][c]=t;
        return f;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n=size(w);
        int r=b.size(),c=b[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(h(0,i,j,b,w)) return 1;
            }
        }
        return 0;
    }
    
    
};