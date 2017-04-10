class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int total = 0; total <= target; total++){
            for(int i = 0; i < nums.size(); i++){
                if(total - nums[i] < 0) continue;
                dp[total] += dp[total - nums[i]];
            }
        }
        return dp[target];
    }
};
