class Solution {
public: 
    void get_next(string t, vector<int> &next){
        int i = 0, j = -1, n = t.size();
        next[0] = -1;
        while(i < n-1){
            if(j == -1 || t[i] == t[j]){
                i++, j++;
                if(t[i] != t[j]) next[i] = j;
                else next[i] = next[j];
            }else{
                j = next[j];
            }
        }
    }
    
    int strStr(string s, string t) {
        int n = s.length(), m = t.length();
        if(m == 0) return 0;
        vector<int> next(m);
        get_next(t, next);
        
        int i = 0, j = 0;
        while(i < n && j < m){
            if(j == -1 || s[i] == t[j]) i++, j++;
            else j = next[j];
        }
        if(j >= m) return i - m;
        else return -1;
    }
};
