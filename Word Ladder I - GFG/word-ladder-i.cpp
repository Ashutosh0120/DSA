//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string b, string e, vector<string>& l) {
        queue<pair<string,int>> q;
        unordered_set<string> m(l.begin(),l.end());
        m.erase(b);
        q.push({b,1});
        while(!q.empty()){
            string a=q.front().first;
            int s=q.front().second;
            q.pop();
            if(a==e){
                return s;
            }
            for(int i=0;i<a.size();i++){
                char o=a[i];
                for(char x='a';x<='z';x++){
                    a[i]=x;
                    if(m.find(a)!=m.end()){
                        q.push({a,s+1});
                        m.erase(a);
                    }
                }
                a[i]=o;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends