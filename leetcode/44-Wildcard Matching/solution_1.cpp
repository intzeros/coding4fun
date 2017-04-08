class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp_pre(m+1, false);
 
        dp_pre[0] = true;
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*') dp_pre[j] = dp_pre[j-1];
        }
        
        for(int i = 1; i <= n; i++){
            vector<bool> dp_cur(m+1, false);
            for(int j = 1; j <= m; j++){
                int ii = i-1, jj = j-1;
                if(s[ii] == p[jj] || p[jj] == '?'){
                    // dp[i][j] = dp[i-1][j-1];
                    dp_cur[j] = dp_pre[j-1];
                }else if(p[jj] == '*'){
                    // dp[i][j] = dp[i][j-1] | dp[i-1][j];
                    dp_cur[j] = dp_cur[j-1] | dp_pre[j];
                }
            }
            dp_pre = dp_cur;
        }
        return dp_pre[m];
    }
};
