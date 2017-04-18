class Solution {
public:
    vector<vector<int> > rst;
    
    void solve(vector<int>& nums, vector<int>& vec, int i){
        if(i == nums.size()){
            rst.push_back(vec);
            return;
        }
        
        vec.push_back(nums[i]);
        solve(nums, vec, i+1);
        vec.pop_back();
        solve(nums, vec, i+1);
    }
 
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, *(new vector<int>()), 0);
        return rst;
    }
};
