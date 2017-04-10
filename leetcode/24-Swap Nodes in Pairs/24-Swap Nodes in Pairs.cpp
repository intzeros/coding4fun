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
    ListNode* swapPairs(ListNode* head) {
        ListNode* H = new ListNode(0), *pre = H, *p, *q, *nxt;
        H->next = head;
        while(pre){
            if(pre->next == NULL || pre->next->next == NULL) break;
            p = pre->next;
            q = pre->next->next;
            nxt = pre->next->next->next;
            
            pre->next = q;
            q->next = p;
            p->next = nxt;
            pre = pre->next->next;
        }
        return H->next;
    }
};
