class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur_max = 0, next_max = 0, ans = 0;
        for(int i = 0; i < n; i++){ 
            if(i > cur_max){
                ans++;
                cur_max = next_max;
            }
            if(i+nums[i] > next_max) next_max = i+nums[i];
        }
        return ans;
    }
};
