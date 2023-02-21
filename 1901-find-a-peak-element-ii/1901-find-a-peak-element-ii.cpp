class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& ma) {
        int r=ma.size(), c=ma[0].size();
        int i=0, j=c-1;
        while(i<r and j<c and j>=0 and i>=0){
            int w=(i-1<0)?-1:ma[i-1][j];
            int x=(j-1<0)?-1:ma[i][j-1];
            int y=(i+1==r)?-1:ma[i+1][j];
            int z=(j+1==c)?-1:ma[i][j+1];
            if(ma[i][j]>x and ma[i][j]>y and ma[i][j]>w and ma[i][j]>z){
                return {i,j};
            }
            int p=max({w,x,y,z});
            if(p==w) i--;
            else if(p==x) j--;
            else if(p==y) i++;
            else j++;
            
        }
        return {};
    }
};