class Solution {
public:
    int maxProduct(vector<int>& v) {
        int ans=v[0],mx=ans,mi=ans;
        int n=size(v);
        for(int i=1;i<n;i++){
            if(v[i]<0){
                swap(mx,mi);
            }
            mx=max(v[i],mx*v[i]);
            mi=min(v[i],mi*v[i]);
            ans=max(mx,ans);
        }
        return ans;
    }
};