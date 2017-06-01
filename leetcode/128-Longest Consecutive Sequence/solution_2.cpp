class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(set.find(nums[i]-1) != set.end()) continue;
            int x = nums[i]+1, len = 1;
            while(set.find(x) != set.end()) x++, len++;
            if(len > ans) ans = len;
        }
        return ans;
    }
};
