class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), max_pos = 0;
        vector<int> dp(n, n-1);
        dp[0] = 0;
        for(int i = 0; i < n; i++){ 
            if(i+nums[i] >= n-1) return min(dp[n-1], dp[i] + 1);
            
            if(i+nums[i] > max_pos){
                for(int j = max_pos+1; j <= i+nums[i] && j < n; j++){
                    dp[j] = dp[i] + 1;
                }
                max_pos = i + nums[i];
            }
        }
        return dp[n-1];
    }
};
