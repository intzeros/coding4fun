class Solution {
public:
    vector<vector<int>> rst;
    
    void solve(int from, vector<int> nums){
        if(from == nums.size()){
            rst.push_back(nums);
            return;
        }
        for(int i = from; i < nums.size(); i++){
            if(i != from && nums[i] == nums[from]) continue;
            swap(nums[from], nums[i]);
            solve(from+1, nums);
        }
    }
 
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return rst;
    }
};
