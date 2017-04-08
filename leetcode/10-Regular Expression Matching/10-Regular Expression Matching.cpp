class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0] = true;
        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int ii = i-1, jj = j-1;
                
                if(s[ii] == p[jj] || p[jj] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[jj] == '*'){
                    if(p[jj-1] == '.'){     // ".*"
                        dp[i][j] = dp[i][j-2] | dp[i-1][j];
                    }else{                  // "a*"
                        dp[i][j] = dp[i][j-2] | (p[jj-1] == s[ii] ? dp[i-1][j] : false);
                    }
                }
            }
        }
        return dp[n][m];
    }
};
