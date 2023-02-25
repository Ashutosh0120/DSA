class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x: nums) m[x]++;
        sort(begin(nums),end(nums),[&](int a, int b){
            return m[a]!=m[b]? m[a]<m[b]:a>b;});
        
        return nums;
    }
};