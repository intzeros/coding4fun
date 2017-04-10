struct cmp{
    bool operator()(const ListNode* n1, const ListNode* n2){    // 小顶堆
        return n1->val > n2->val;
    }
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* H = new ListNode(0), *tail = H, *p;
        priority_queue<ListNode*, vector<ListNode*>, cmp> Q;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                Q.push(lists[i]);
            }
        }
        
        while(!Q.empty()){
            p = Q.top();
            Q.pop();
            
            tail->next = p;
            tail = p;
            p = p->next;
            if(p) Q.push(p);
        }
        return H->next;
    }
};
