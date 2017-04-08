class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans, min = 0x3f3f3f3f;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int le = i+1, ri = n-1;
            while(le < ri){
                int sum = nums[le] + nums[ri] + nums[i];
                if(abs(target - sum) < min){
                    ans = sum;
                    min = abs(target - sum);
                }
                
                if(sum < target) le++;
                else ri--;
            }
        }
        return ans;
    }
};
