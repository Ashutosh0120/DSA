class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n=size(nums);
        int e1=-1, e2=-1, c1=0, c2=0;
        for(int i=0;i<n;i++){
            if(e1==nums[i]) c1++;
            else if(e2==nums[i]) c2++;
            else if(c1==0){
                c1=1; e1=nums[i];
            }
            else if(c2==0){
                c2=1; e2=nums[i];
            }
            else {
                c1--; c2--;
            }
        }
        c1=c2=0;
        for(auto x: nums){
            if(x==e1) c1++;
            else if(x==e2) c2++;
        }
        if(c1>(n/3)) v.push_back(e1);
        if(c2>(n/3)) v.push_back(e2);
        return v;

    }
};