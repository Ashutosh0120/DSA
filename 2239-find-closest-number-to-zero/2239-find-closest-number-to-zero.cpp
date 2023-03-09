class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mx=INT_MAX;
        for(auto x: nums){
            if(abs(x)<abs(mx)){
                mx=x;
            }
            else if(abs(x)==abs(mx)) mx=max(mx,x);
        }
        return mx;
    }
};