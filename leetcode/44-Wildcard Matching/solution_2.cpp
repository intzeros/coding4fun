class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0, pstar = -1, spos;
        while(i < n){
            if(j < m && s[i] == p[j] || p[j] == '?') i++, j++;
            else if(j < m && p[j] == '*'){
                spos = i;
                pstar = j;
                j++;
            }else if(pstar != -1){
                i = ++spos;
                j = pstar + 1;
            }else return false;
        }
        while(j < m && p[j] == '*') j++;
        return j == m;
    }
};
