//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* rev(Node* n){
        Node* p=NULL;
        while(n!=NULL){
            Node* nx=n->next;
            n->next=p;
            p=n;
            n=nx;
        }
        return p;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* f=head, *s=head;
        if(head==NULL or head->next==NULL) 
            return true;
        while(f->next and f->next->next){
            s=s->next;
            f=f->next->next;
        }
        s->next=rev(s->next);
        s=s->next;
        Node* t=head;
        while(s!=NULL){
            if(s->data!=t->data){
                return false;
            }
            s=s->next;
            t=t->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends