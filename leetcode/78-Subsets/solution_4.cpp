class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst(1);
        for(int i = 0; i < nums.size(); i++){
            int m = rst.size();
            for(int j = 0; j < m; j++){
                vector<int> vec(rst[j]);
                vec.push_back(nums[i]);
                rst.push_back(vec);
            }
        }
        return rst;
    }
};
