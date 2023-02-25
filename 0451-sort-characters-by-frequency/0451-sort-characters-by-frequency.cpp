class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        map<char,int> m;
        for(auto x: s) m[x]++;
        priority_queue<pair<int,char>>p;
        for(auto x: m){
            p.push({x.second,x.first});
        }
        while(!p.empty()){
            ans+=string(p.top().first,p.top().second);
            p.pop();
        }
        return ans;
    }
};