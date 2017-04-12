class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_pos = 0;
        for(int i = 0; i < n; i++){
            if(max_pos < i) return false;
            if(nums[i] + i > max_pos) max_pos = nums[i] + i;
        }
        return max_pos >= n-1;
    }
};
