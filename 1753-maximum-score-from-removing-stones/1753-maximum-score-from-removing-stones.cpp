class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> p;
        int r=0;
        p.push(a);p.push(b);p.push(c);
        while(p.size()>1){
            int a=p.top();p.pop();
            int b=p.top();p.pop();
            a--; b--;
            r++;
            if(a>0) p.push(a);
            if(b>0) p.push(b);
        }
        return r;
    }
};