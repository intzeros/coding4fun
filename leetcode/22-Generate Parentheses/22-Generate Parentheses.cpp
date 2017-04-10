class Solution {
public:
    void generate(int leftNum, int rightNum, string s, vector<string> &rst){
        if(leftNum == 0 && rightNum == 0){
            rst.push_back(s);
            return;
        }
        
        if(leftNum > 0){
            generate(leftNum-1, rightNum, s+"(", rst);
        }
        if(rightNum > 0 && rightNum > leftNum){
            generate(leftNum, rightNum-1, s+")", rst);
        }
    }
    
    vector<string> generateParenthesis(int n){
        vector<string> rst;
        generate(n, n, "", rst);
        return rst;
    }
};
