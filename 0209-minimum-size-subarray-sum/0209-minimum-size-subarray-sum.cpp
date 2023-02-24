class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int len = INT_MAX;
        int left = 0, right = 0,sum = 0;
        while (right < v.size()){
            sum += v[right++];
            while (sum >= t){
                len = min(len, right - left);
                sum -= v[left++];
            }
        }
        return (len < INT_MAX) ? len : 0;
    }
};