class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int n=size(nums);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!d.empty() and d.front()==(i-k)) d.pop_front();
            while(!d.empty() and nums[d.back()]<=nums[i]) d.pop_back();
            d.push_back(i);
            if(i>=(k-1)) ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};