/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) return NULL;
        ListNode *s=head, *f=head, *t=head;
        while(f->next and f->next->next){
            s=s->next; f=f->next->next;
            if(s==f){
                while(s!=t){
                    s=s->next;
                    t=t->next;
                }
                return t;
            }
        }
    
        return NULL;
    }
};