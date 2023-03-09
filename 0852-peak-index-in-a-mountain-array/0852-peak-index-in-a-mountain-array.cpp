class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& v) {
        return max_element(begin(v),end(v))-begin(v);
    }
};