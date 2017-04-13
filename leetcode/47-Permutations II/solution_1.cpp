class Solution {
public:
    void solve(int from, vector<int>& nums, set<vector<int>>& rst){
        if(from == nums.size()){
            rst.insert(nums);
            return;
        }
        for(int i = from; i < nums.size(); i++){
            if(i != from && nums[i] == nums[i-1]) continue;
            swap(nums[from], nums[i]);
            solve(from+1, nums, rst);
            swap(nums[from], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> rst;
        solve(0, nums, rst);
        return vector<vector<int>>(rst.begin(), rst.end());
    }
};
