class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x: nums) m[x]++;
        int mi=*min_element(begin(nums),end(nums));
        int mx=*max_element(begin(nums),end(nums));
        int r=0;
        for(int i=mi;i<=mx;i++){
            while(m[i]>0){
                nums[r]=i;
                m[i]--;
                r++;
            }
        }
        return nums;
    }
};