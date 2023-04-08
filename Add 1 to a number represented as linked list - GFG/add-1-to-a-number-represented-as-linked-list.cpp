//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends


class Solution
{
    public:
    Node * rev(Node * h){
        Node *p=NULL, *c=h;
        while(c){
            Node *n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    Node* addOne(Node *head) 
    {
        int sum=0, carry=0;
        Node *t=rev(head);
        Node *r=t;
        Node *p=NULL, *c=t;
        while(c){
            sum=0;
            if(p==NULL) sum=c->data+1;
            else sum=c->data+carry;
            c->data=sum%10;
            carry=sum/10;
            p=c;
            c=c->next;
        }
        if(carry==1){
            Node *ne=new Node(1);
            p->next=ne;
        }
        return rev(t);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends