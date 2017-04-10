class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head, *p2 = head;
        while(n--){
            p1 = p1->next;
        }
        if(p1 == NULL){
            return head->next;
        }
        while(p1->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};
