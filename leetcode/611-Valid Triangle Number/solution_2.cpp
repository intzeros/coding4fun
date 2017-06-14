class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 2; i < n; i++){
            int le = 0, ri = i-1;
            while(le < ri){
                if(nums[le] + nums[ri] > nums[i]){
                    ans += ri-le;
                    ri--;
                }else le++;
            }
        }
        return ans;
    }
};