class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto x: arr) if(x<=k) k++;
        
        return k;
    }
};