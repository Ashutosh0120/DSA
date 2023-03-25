//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int d,int k){
        int n=image.size(), m=image[0].size();
        if(i>=n or i<0 or j<0 or j>=m or image[i][j]!=k) return;
        image[i][j]=d;
        dfs(image,i+1,j,d,k);dfs(image,i,j+1,d,k);dfs(image,i-1,j,d,k);dfs(image,i,j-1,d,k);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int d) {
        // Code here 
        int k=image[sr][sc];
        if(k==d) {
            return image;
        }
        dfs(image,sr,sc,d,k);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends