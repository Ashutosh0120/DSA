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
private:
    int l=0;
    ListNode *p;
public:
    Solution(ListNode* head) {
        p=head;
        ListNode *t=head;
        while(t){
            l++; t=t->next;
        }
    }
    int getRandom() {
        int r=rand()%l;
        ListNode* t=p;
        for(int i=0;i<r;i++){
            t=t->next;
        }
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */