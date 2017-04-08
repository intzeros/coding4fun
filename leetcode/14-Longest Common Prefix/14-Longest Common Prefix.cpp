class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        
        int i = 0;
        while(true){
            int k = 0;
            while(k < n && i < strs[k].size() && strs[k][i] == strs[0][i]) k++;
            if(n == k) i++;
            else break;
        }
        return strs[0].substr(0, i);
    }
};
