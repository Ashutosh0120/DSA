class Solution {
public:
    bool h(int mid,vector<int>& candies, long long k)
    {
        long long int c=0;
        for(int i=0;i<candies.size();i++)
        {
            c+=candies[i]/mid;
        }
        return c>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int s=1,e=1e9, ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(h(mid,candies,k))
            {
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};