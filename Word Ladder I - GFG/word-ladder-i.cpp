//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string b, string e, vector<string>& l) {
        // Code here
        queue<pair<string,int>> q;
        q.push({b,1});
        unordered_set<string>s(begin(l),end(l));
        s.erase(b);
        while(!q.empty()){
            string a=q.front().first;
            int p=q.front().second;
            q.pop();
            if(a==e) return p;
            int x=a.size();
            for(int i=0;i<x;i++){
                char o=a[i];
                for(char c='a';c<='z';c++){
                    a[i]=c;
                    if(s.find(a)!=s.end()){
                        s.erase(a);
                        q.push({a,p+1});
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