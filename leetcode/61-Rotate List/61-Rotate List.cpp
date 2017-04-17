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
        ListNode *p = head, *tail;
        int n = 0;
        while(p){
            tail = p;
            p = p->next;
            n++;
        }
        
        k = k % n;
        ListNode* q = head;
        for(int i = 0; i < n-k-1; i++){
            q = q->next;
        }
        tail->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};
