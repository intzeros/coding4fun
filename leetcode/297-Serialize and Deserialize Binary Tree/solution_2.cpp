class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "null";
        else{
            return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return mydeserialize(ss);
    }
    
private:
    TreeNode* mydeserialize(stringstream& ss) {
        string buf;
        ss >> buf;
        if(buf == "null") return NULL;
        else{
            TreeNode* p = new TreeNode(stoi(buf));
            p->left = mydeserialize(ss);
            p->right = mydeserialize(ss);
            return p;
        }
    }
};
