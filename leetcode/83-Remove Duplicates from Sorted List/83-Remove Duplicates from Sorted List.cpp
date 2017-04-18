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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p && p->next){
            if(p->next->val == p->val){
                ListNode *q = p->next;
                p->next = p->next->next;
                delete q;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};
