class Solution {
public:
    vector<string> rst;
    string symbols[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> rst;
        if(n == 0) return rst;
        else rst.push_back("");
        
        for(int k = 0; k < n; k++){
            int m = symbols[digits[k]-'0'].size();
            if(m == 0) continue;
            
            int nn = rst.size();
            for(int i = 0; i < nn; i++){
                for(int j = 0; j < m; j++){
                    rst.push_back(rst[i] + symbols[digits[k]-'0'][j]);
                }
            }
            rst.erase(rst.begin(), rst.begin()+nn);
        }
        return rst;
    }
};
