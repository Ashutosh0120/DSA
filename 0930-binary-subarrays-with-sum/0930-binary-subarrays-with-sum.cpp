class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=0,s=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s==goal) a++;
            if(m.find(s-goal)!=m.end()) a+=m[s-goal];
            m[s]++;
        }
        return a;
    }
};