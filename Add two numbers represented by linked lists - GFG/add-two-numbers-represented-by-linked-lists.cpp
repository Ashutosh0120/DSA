//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node *rev(Node *h){
        Node *t=h,*p=NULL;
        while(t){
            Node *n=t->next;
            t->next=p;
            p=t;
            t=n;
        }
        return p;
    }
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        
        Node *d=new Node(-1);
        Node *t=d;
        int c=0;
        l1=rev(l1);
        l2=rev(l2);
        while(l1!=NULL or l2!=NULL or c){
            int s=0;
            if(l1!=NULL){
                s+=l1->data; l1=l1->next;
            }
            if(l2!=NULL){
                s+=l2->data; l2=l2->next;
            }
            s+=c;
            c=s/10;
            Node *n=new Node(s%10);
            t->next=n;
            t=t->next;
        }
        
        d=d->next;
        d=rev(d);
        return d;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends