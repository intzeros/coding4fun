class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++){
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums[i] < nums[j];
        });
        
        int le = 0, ri = n-1;
        vector<int> rst;
        while(le < ri){
            if(nums[idx[le]] + nums[idx[ri]] == target){
                rst.push_back(idx[le]);
                rst.push_back(idx[ri]);
                return rst;
            }else if(nums[idx[le]] + nums[idx[ri]] > target) ri--;
            else le++;
        }
        return rst;
    }
};
