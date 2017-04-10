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
    bool check_K(ListNode* p, int k){
        int i = 0;
        while(i < k && p) p = p->next, i++;
        return i == k;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* H = new ListNode(0), *HH = H, *p = head, *q, *tail = H;
        while(check_K(p, k)){
            tail = p;
            for(int i = 0; i < k && p; i++){
                q = p->next;
                p->next = HH->next;
                HH->next = p;
                p = q;
            }
            HH = tail;
        }
        if(p) tail->next = p;
        return H->next;
    }
};
