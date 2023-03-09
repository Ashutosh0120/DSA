class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> p;
        vector<int> a;
        for(auto a: arr){
            int a1=abs(a-x);
            p.push({a1,a});
            if(p.size()>k) p.pop();
        }
        while(!p.empty()){
            a.push_back(p.top().second);
            p.pop();
        }
        sort(begin(a),end(a));
        return a;
    }
};