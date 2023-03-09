class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x: nums) m[x]++;
        priority_queue<pair<int,int>>p;
        for(auto x: m){
            p.push({x.second,x.first});
        }
        vector<int> v;
        int a=0;
        while(a<k){
            v.push_back(p.top().second);
            p.pop();
            a++;
        }
        return v;
    }
};