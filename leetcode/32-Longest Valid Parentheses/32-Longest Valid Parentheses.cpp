class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            if(s[i] == '(') continue;
            
            int k = i - dp[i-1];
            if(k-1 >= 0 && s[k-1] == '('){
                dp[i] = dp[i-1] + 2;
                if(k-2 >= 0 && s[k-2] == ')') dp[i] += dp[k-2];
            }
            
            if(ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};
