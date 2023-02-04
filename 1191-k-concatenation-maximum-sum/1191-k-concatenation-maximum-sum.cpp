class Solution {
int m=1e9+7;
public:
    long long ka(vector<int> &arr){
        long long ans=INT_MIN;
        long long cs=0;
        long long n=arr.size();
        for(int i=0;i<n;i++){
            cs+=arr[i];
            if(cs>ans) ans=cs;

            if(cs<0) cs=0;
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long n=arr.size();
        long long s=accumulate(begin(arr),end(arr),0);
        long long ans=0;
        long long r=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                r=1;
            }
        }
        if(!r){
            return 0;
        }
        if(k==1) {
            ans=ka(arr);
            return ans%m;	
        }

        for(int i=0;i<n;i++){
           
            arr.push_back(arr[i]);
        }
       
        if(s<0){
            ans=ka(arr);
            // return (int)ans%m;
        }
        else {
            ans=((ka(arr)%m) +(((k-2)*s)%m))%m;
        }
        return (int)ans%m;
    }

};