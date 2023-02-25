#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
	//code
	ll t; cin>>t;
	while(t--){
	    ll n; cin>>n;
	    vector<ll> v(n);
	    map<ll,ll> m;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        m[v[i]]++;
	    }
	    sort(v.begin(),v.end(),[&](int a, int b){
	        return (m[a]==m[b])? (a<b):(m[a]>m[b]);
	    });
	    
	    for(auto x: v){
	        cout<<x<<' ';
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}