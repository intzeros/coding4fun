class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rst(1);
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] != nums[i-1]) start = 0;
            int m = rst.size();
            for(int j = start; j < m; j++){
                vector<int> vec(rst[j]);
                vec.push_back(nums[i]);
                rst.push_back(vec);
            }
            start = m;
        }
        return rst;
    }
};
