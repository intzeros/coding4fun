typedef struct Node {
    int val, idx;
}Node;
 
int cmp(const Node &n1, const Node &n2){
    return n1.val < n2.val;
}
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst;
        int n = nums.size();
        vector<Node> nodes(n);
        for(int i = 0; i < n; i++){
            nodes[i].val = nums[i];
            nodes[i].idx = i;
        }
        sort(nodes.begin(), nodes.end(), cmp);
 
        //从两头往中间查找的方式
        int le = 0, ri = n-1;
        while(le < ri){
            if(nodes[le].val + nodes[ri].val == target){
                rst.push_back(nodes[le].idx);
                rst.push_back(nodes[ri].idx);
                return rst;
            }else if(nodes[le].val + nodes[ri].val > target){
                ri--;
            }else{
                le++;
            }
        }
        return rst;
    }
};
