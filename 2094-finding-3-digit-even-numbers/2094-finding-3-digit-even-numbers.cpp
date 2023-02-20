class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        map<int,int> m;
        for(auto x: digits) m[x]++;
        for(int i=100;i<=998;i+=2){
            int a=(i%10), b=((i/10)%10),c=(i/100);
            m[a]--;m[b]--;m[c]--;
            if(m[a]>=0 and m[b]>=0 and m[c]>=0) ans.push_back(i);
            m[a]++;m[b]++;m[c]++;
        }
        return ans;
    }
};