class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(auto x: stones) p.push(x);
        while(p.size()>1){
            int a=p.top(); p.pop();
            int b=p.top(); p.pop();
            int c=abs(a-b);
            p.push(c);
        }
        return p.top();
    }
};