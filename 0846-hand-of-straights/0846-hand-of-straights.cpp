class Solution {
public:
    bool isNStraightHand(vector<int>& v, int g) {
        if(v.size()%g!=0) return false;
        map<int,int> m;
        for(auto x:v) m[x]++;
        while(!m.empty()){
            int a=m.begin()->first;
            for(int i=0;i<g;i++){
                if(m[a+i]==0)  return false;
                else if(--m[a+i]<1) m.erase(a+i);
            }
        }
        return true;
        
    }
};