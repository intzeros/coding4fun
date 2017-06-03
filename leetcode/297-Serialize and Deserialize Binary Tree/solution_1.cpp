class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        string rst;
        queue<TreeNode*> Q;
        Q.push(root);
        rst = to_string(root->val);
        while(!Q.empty()){
            int n = Q.size();
            while(n--){
                TreeNode* now = Q.front();
                Q.pop();
                if(now->left){
                    rst += " " + to_string(now->left->val);
                    Q.push(now->left);
                }else{
                    rst += " null";
                }
                
                if(now->right){
                    rst += " " + to_string(now->right->val);
                    Q.push(now->right);
                }else{
                    rst += " null";
                }
            }
        }
        return rst;
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        vector<string> nodes;
        stringstream ss(data);
        string buf;
        while(ss >> buf){
            nodes.push_back(buf);
        }
        
        TreeNode* head = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> Q;
        Q.push(head);
        int i = 1;
        while(!Q.empty()){
            int n = Q.size();
            while(n--){
                TreeNode* now = Q.front();
                Q.pop();
                if(i < nodes.size() && nodes[i] != "null"){
                    TreeNode* p = new TreeNode(stoi(nodes[i]));
                    Q.push(p);
                    now->left = p;
                }
                i++;
                if(i < nodes.size() && nodes[i] != "null"){
                    TreeNode* p = new TreeNode(stoi(nodes[i]));
                    Q.push(p);
                    now->right = p;
                }
                i++;
            }
        }
        return head;
    }
};
