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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node * f(Node *root, int target, unordered_map<Node*,Node*> &pm){
        Node *e;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *c=q.front(); q.pop();
            if(c->data==target) {
                e=c;
            }
            if(c->left){
                pm[c->left]=c;
                q.push(c->left);
            }
            if(c->right){
                pm[c->right]=c;
                q.push(c->right);
            }
        }
        return e;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> pm;
        Node *t=f(root,target,pm);
        unordered_map<Node*, int> v;
        int l=0;
        queue<Node*> q;
        q.push(t);
        v[t]=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node *c=q.front(); q.pop();
                
                if(!v[c->left] and c->left){
                    v[c->left]=1;
                    q.push(c->left);
                }
                if(!v[c->right] and c->right){
                    v[c->right]=1;
                    q.push(c->right);
                }
                if(pm[c] and !v[pm[c]]){
                    v[pm[c]]=1;
                    q.push(pm[c]);
                }
            }
            l++;
        }
        return l-1;
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