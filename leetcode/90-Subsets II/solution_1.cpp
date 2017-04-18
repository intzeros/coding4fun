class Solution {
public:
    vector<vector<int>> rst;
    
    void solve(vector<int>& nums, vector<int>& vec, int from){
        rst.push_back(vec); // 直接 push
        for(int i = from; i < nums.size(); i++){
            if(i != from && nums[i] == nums[i-1]) continue; // 去重
            vec.push_back(nums[i]);
            solve(nums, vec, i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, *(new vector<int>()), 0);
        return rst;
    }
};
