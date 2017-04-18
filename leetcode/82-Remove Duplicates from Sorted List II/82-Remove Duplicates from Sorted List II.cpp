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
        ListNode* H = new ListNode(0), *pre = H;
        H->next = head;
        while(pre){
            if(pre->next && pre->next->next && pre->next->val == pre->next->next->val){
                int k = pre->next->val;
                while(pre->next && pre->next->val == k){
                    ListNode* q = pre->next;
                    pre->next = pre->next->next;
                    delete q;
                }
            }else{
                pre = pre->next;
            }
        }
        return H->next;
    }
};
