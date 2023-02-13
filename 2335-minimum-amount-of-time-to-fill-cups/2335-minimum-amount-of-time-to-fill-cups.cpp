class Solution {
public:
    int fillCups(vector<int>& amount) {
        int s=accumulate(begin(amount),end(amount),0);
        int m=*max_element(begin(amount),end(amount));
        return max(m,(s+1)/2);
    }
};