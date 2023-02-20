/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 or head==NULL) return head;
        ListNode *d=new ListNode(-1);
        d->next=head;
        
        int t=0;
        ListNode *c=head;
        while(c){
            c=c->next;
            t++;
        }
        c=head;
        ListNode *p=d, *n=NULL;
        while(t>=k){
            c=p->next;
            n=c->next;
            for(int i=0;i<k-1;i++){
                c->next=n->next;
                n->next=p->next;
                p->next=n;
                n=c->next;
            }
            p=c;
            t-=k;
        }
        return d->next;
    }
};