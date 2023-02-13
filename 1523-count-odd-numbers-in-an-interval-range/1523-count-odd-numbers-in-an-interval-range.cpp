class Solution {
public:
    int countOdds(int l, int h) {
        int r1=(l/2);
        int r2=((h+1)/2);
        return r2-r1;
    }
};