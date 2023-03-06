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
    ListNode* mergeKLists(vector<ListNode*>& l) {
        ListNode *t=new ListNode(-1);
        if(l.size()==0) return NULL;
        ListNode *h=t;
        vector<int> v;
        for(ListNode *a: l){
            while(a)
            {
                v.push_back(a->val); a=a->next;
            }
        }
        sort(begin(v),end(v));
        for(int &x: v){
            t->next=new ListNode(x);
            t=t->next;
        }
        return h->next;
    }
};