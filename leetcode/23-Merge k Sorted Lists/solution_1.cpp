class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* H = new ListNode(0), *tail = H;
        while(true){
            int min = 0x3f3f3f3f, k = -1;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] && lists[i]->val < min){
                    k = i;
                    min = lists[i]->val;
                }
            }
            if(k == -1) break;
            tail->next = lists[k];
            tail = lists[k];
            lists[k] = lists[k]->next;
        }
        return H->next;
    }
};
