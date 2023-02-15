class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=size(num),c=0;
        for(int i=n-1;i>=0;i--){
            int s=num[i]+c+k%10;
            num[i]=s%10;
            c=s/10;k=k/10;
            if(!k and !c) break;
        }
        while(k){
            int v=k%10+c; k/=10;
            num.insert(begin(num),v%10);
            c=v/10;
        }
        if(c) num.insert(begin(num),c);
        return num;
        
    }
};