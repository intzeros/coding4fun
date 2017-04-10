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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1, *q = l2, *H = new ListNode(0), *tail = H;
        while(p && q){
            if(p->val < q->val){
                tail->next = p;
                tail = p;
                p = p->next;
            }else{
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }
        if(p) tail->next = p;
        if(q) tail->next = q;
        return H->next;
    }
};
