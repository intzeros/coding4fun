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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int n = 1;
        ListNode *tail = head;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        k = k % n;
        if(k == 0) return head;
        
        int m = n-k-1;
        ListNode *p = head;
        while(m--) p = p->next;
        tail->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
