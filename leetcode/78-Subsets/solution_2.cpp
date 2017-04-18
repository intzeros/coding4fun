class Solution {
public:
    vector<vector<int> > rst;
    
    void solve(vector<int>& nums, vector<int>& vec, int from){
        rst.push_back(vec);
        for(int i = from; i < nums.size(); i++){
            vec.push_back(nums[i]);
            solve(nums, vec, i+1);
            vec.pop_back();
        }
    }
 
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, *(new vector<int>()), 0);
        return rst;
    }
};
