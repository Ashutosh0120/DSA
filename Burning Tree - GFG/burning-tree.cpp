//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    Node* f(Node *t, unordered_map<Node*,Node*> &pa,int p){
        queue<Node*>q;
        q.push(t);
        Node *k;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                Node *t=q.front(); q.pop();
                if(p==t->data)
                {
                    k=t;
                }
                if(t->left){
                    q.push(t->left);
                    pa[t->left]=t;
                }
                if(t->right){
                    q.push(t->right);
                    pa[t->right]=t;
                }
            }
        }
        return k;
    }
    int minTime(Node* root, int t) 
    {
        int ans=0;
        unordered_map<Node*,Node*> pa;
        Node *t1=f(root,pa,t);
        unordered_map<Node*,bool> v;
        v[t1]=1;
        queue<Node*>q;
        q.push(t1);
        while(!q.empty())
        {
            int s=q.size();
            while(s--){
                Node *x=q.front(); q.pop();
                if(x->left and !v[x->left]){
                    q.push(x->left);
                    v[x->left]=1;
                }
                if(x->right and !v[x->right]){
                    q.push(x->right);
                    v[x->right]=1;
                }
                if(pa[x] and !v[pa[x]]){
                    q.push(pa[x]);
                    v[pa[x]]=1;
                }
            }
            ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends