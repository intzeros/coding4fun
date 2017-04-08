class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* p1 = l1, *p2 = l2, *H = new ListNode(0), *tail = H;
        while(true){
            int sum = c;
            if(p1) sum += p1->val;
            if(p2) sum += p2->val;
            ListNode* node = new ListNode(sum % 10);
            tail->next = node;
            tail = node;
            if(sum >= 10) c = 1;
            else c = 0;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
            if(p1 == NULL && p2 == NULL && c == 0) break;
        }
        return H->next;
    }
};
