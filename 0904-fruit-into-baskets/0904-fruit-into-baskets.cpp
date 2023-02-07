class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i=0, j=0, n=f.size();
        map<int,int> m;
        while(i<n){
            m[f[i]]++;
            if(m.size()>2){
                m[f[j]]--;
                if(m[f[j]]==0) m.erase(f[j]);
                j++;
            }
            i++;
        }
        return i-j;
        
    }
};