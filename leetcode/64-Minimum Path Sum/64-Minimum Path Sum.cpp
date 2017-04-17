class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> dp(grid);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0) dp[i][j] += dp[i][j-1];
                else if(j == 0) dp[i][j] += dp[i-1][j];
                else dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
