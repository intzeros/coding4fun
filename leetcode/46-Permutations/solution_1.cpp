class Solution {
public:
    vector<vector<int>> rst;
    
    void solve(int from, vector<int>& nums){
        if(from == nums.size()){
            rst.push_back(nums);
            return;
        }
        for(int i = from; i < nums.size(); i++){
            swap(nums[from], nums[i]);
            solve(from+1, nums);
            swap(nums[from], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return rst;
    }
};
