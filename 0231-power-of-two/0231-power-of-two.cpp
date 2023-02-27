class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c=0;
        if(!n) return 0;
        while(n){
            if(n&1) c++;
            if(c>1) return 0;
            n=n>>1;
        }
        return 1;
    }
};